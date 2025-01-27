#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct boundary {
  int value;
  bool direction;

  boundary(int value, bool direction) : value(value), direction(direction) {}

  ~boundary() {}
};

vector<vector<int>> merge(vector<vector<int>> &intervals);

void sortBoundaries(vector<boundary> &boundaries);

bool compareBoundaries(const boundary &b1, const boundary &b2) {
  if (b1.value == b2.value) {
    return b1.direction;
  }
  return b1.value < b2.value;
}

int main(int argc, char **argv) {
  int n;
  cout << "Enter the number of intervals: ";
  cin >> n;

  vector<vector<int>> intervals;
  cout << "Enter the intervals in the format [start, end]: " << endl;
  for (int i = 0; i < n; i++) {
    int start, end;
    cin >> start >> end;
    intervals.push_back({start, end});
  }

  vector<vector<int>> mergedIntervals = merge(intervals);

  cout << "Merged Intervals: " << endl;
  for (vector<int> interval : mergedIntervals) {
    cout << "[" << interval[0] << ", " << interval[1] << "] ";
  }
  cout << endl;

  return 0;
}

vector<vector<int>> merge(vector<vector<int>> &intervals) {
  vector<boundary> boundaries;
  vector<vector<int>> res;

  for (vector<int> i : intervals) {
    boundary start(i[0], true);
    boundary end(i[1], false);
    boundaries.push_back(start);
    boundaries.push_back(end);
  }

  sortBoundaries(boundaries);
  int depth = 0;
  int start;

  for (boundary i : boundaries) {
    if (depth == 0) {
      start = i.value;
    }

    depth += i.direction ? 1 : -1;

    if (depth == 0) {
      res.push_back({start, i.value});
    }
  }

  return res;
}

void sortBoundaries(vector<boundary> &boundaries) {
  sort(boundaries.begin(), boundaries.end(), compareBoundaries);
}
