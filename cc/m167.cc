#include <iostream>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int> &numbers, int target);

int main(int argc, char **argv) {
  vector<int> numbers;
  int target;

  // Get input from the user
  int num;
  cout << "Enter the numbers (enter -1 to stop): ";
  while (cin >> num && num != -1) {
    numbers.push_back(num);
  }

  cout << "Enter the target sum: ";
  cin >> target;

  // Call the twoSum function
  vector<int> result = twoSum(numbers, target);

  // Display the result
  if (result.size() == 2) {
    cout << "Indices: " << result[0] << ", " << result[1] << endl;
    cout << "Numbers: " << numbers[result[0] - 1] << ", "
         << numbers[result[1] - 1] << endl;
  } else {
    cout << "No two numbers found that add up to the target." << endl;
  }

  return 0;
}

vector<int> twoSum(vector<int> &numbers, int target) {
  int index2;
  for (index2 = 1; index2 < numbers.size(); ++index2) {
    if (numbers[0] + numbers[index2] >= target) {
      break;
    }
  }
  if (index2 == numbers.size()) {
    --index2;
  }

  int index1 = 0;

  while (index1 < index2) {
    if (numbers[index1] + numbers[index2] == target) {
      vector<int> ans({index1 + 1, index2 + 1});
      return ans;
    }

    if (numbers[index1] + numbers[index2] > target) {
      index2--;
    } else {
      index1++;
    }
  }

  return vector<int>({-1});
}
