#include <iostream>
#include <string>

using namespace std;

int addMinimum(string word) {
  word.insert(0, "c");
  word.push_back('a');

  int sum = 0;

  for (int i = 1; i < word.length(); ++i) {
    sum += ((word[i] + 2 - word[i - 1]) % 3);
  }

  return sum;
}

int main(int argc, char **argv) {
  std::string input;
  std::cout << "Enter a string using only a, b, and c: ";
  std::cin >> input;

  int minimum = addMinimum(input);
  std::cout << "Minimum value: " << minimum << std::endl;

  return 0;
}
