#include <iostream>
#include <string>

int romanToInt(std::string s) {
  int res = 0;
  for (int i = 0; i < s.size(); ++i) {
    switch (s[i]) {
    case 'M':
      res += 1000;
      break;
    case 'D':
      res += 500;
      break;
    case 'C':
      res += (i + 1 < s.size() && (s[i + 1] == 'D' || s[i + 1] == 'M')) ? -100
                                                                        : 100;
      break;
    case 'L':
      res += 50;
      break;
    case 'X':
      res +=
          (i + 1 < s.size() && (s[i + 1] == 'L' || s[i + 1] == 'C')) ? -10 : 10;
      break;
    case 'V':
      res += 5;
      break;
    case 'I':
      res +=
          (i + 1 < s.size() && (s[i + 1] == 'V' || s[i + 1] == 'X')) ? -1 : 1;
      break;
    default:
      std::cerr << "Invalid input" << std::endl;
      return -1;
    }
  }
  return res;
}
