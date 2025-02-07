#include <iostream>

using namespace std;

int smallestValue(int n) {
  int newNum = 0;
  int backup = n;
  for (int i = 2; i <= n; i++) {
    if (n % i == 0) {
      n /= i;
      newNum += i;
      i--;
    }
  }

  if (newNum != backup) {
    newNum = smallestValue(newNum);
  }

  return newNum;
}

int main(int argc, char **argv) {
  int input;
  cout << "Enter a number: ";
  cin >> input;

  int result = smallestValue(input);

  cout << "The smallest value is: " << result << endl;

  return 0;
}
