#include <iostream>
#include <string>

using namespace std;

int minLength(string s) {
  char last = 0;

  for (int i = 0; i < s.length(); ++i) {
    if ((s[i] == 'A' && s[i + 1] == 'B') || s[i] == 'C' && s[i + 1] == 'D') {
      s.erase(i, 2);
      i -= i ? 2 : 1;
    }
  }

  return s.length();
}

int main(int argc, char** argv) {
  std::string input;
  std::cout << "Enter a string: ";
  std::cin >> input;

  int result = minLength(input);
  std::cout << "Minimum length: " << result << std::endl;
}
