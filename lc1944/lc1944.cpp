#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> canSeePersonsCount(vector<int>& heights);

int main(int argc, char** argv) {
  // Get input from the user
  int n;
  cout << "Enter the number of heights: ";
  cin >> n;

  vector<int> heights(n);
  cout << "Enter the heights: ";
  for (int i = 0; i < n; ++i) {
    cin >> heights[i];
  }

  // Call the canSeePersonsCount function
  vector<int> result = canSeePersonsCount(heights);

  // Print the result
  cout << "Result: ";
  for (int i = 0; i < n; ++i) {
    cout << result[i] << " ";
  }
  cout << endl;

  return 0;
}

vector<int> canSeePersonsCount(vector<int>& heights) {
  vector<int> result;
  int count = heights.size();
  stack<int> st;

  size_t stack_size = 0;

  for (int i = count - 1; i > 0; --i) {
    while (!st.empty() && st.top() < heights[i]) {
      st.pop();
    }
    st.push(heights[i]);
    result[i] = stack_size;
    ++stack_size;
  }

  return result;
}