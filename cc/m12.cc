#include <string>
#include <unordered_map>

std::string intToRoman(int num) {
  std::string res;
  std::unordered_map<int, std::string> mapping = {
      {1, "I"},   {4, "IV"},   {5, "V"},   {9, "IX"},  {10, "X"},
      {40, "XL"}, {50, "L"},   {90, "XC"}, {100, "C"}, {400, "CD"},
      {500, "D"}, {900, "CM"}, {1000, "M"}};

  int div = 1000;
  while (num > 0) {
    int n = num / div;
    if (n > 0) {
      if (n == 9 || n == 4) {
        res += mapping[n * div];
      } else {
        if (n >= 5) {
          res += mapping[5 * div];
          n -= 5;
        }
        for (int i = 0; i < n; ++i) {
          res += mapping[div];
        }
      }
    }
    num %= div;
    div /= 10;
  }

  return res;
}