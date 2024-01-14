#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string repeatLimitedString(string s, int repeatLimit) {
  vector<char> copy;
  for(char i : s) {
    copy.push_back(i);
  }

  make_heap(copy.begin(), copy.end(), less<char>());
}

int main(int argc, char** argv) {}
