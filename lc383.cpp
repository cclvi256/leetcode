#include <iostream>
#include <string>

using namespace std;

bool canConstruct(string ransomNote, string magazine);

int main(int argc, char** argv) {
  string ransomNote, magazine;

  // Get user input for ransom note
  cout << "Enter the ransom note: ";
  getline(cin, ransomNote);

  // Get user input for magazine
  cout << "Enter the magazine: ";
  getline(cin, magazine);

  // Call the canConstruct function and print the result
  if (canConstruct(ransomNote, magazine)) {
    cout << "Ransom note can be constructed from the magazine." << endl;
  } else {
    cout << "Ransom note cannot be constructed from the magazine." << endl;
  }

  return 0;
}

bool canConstruct(string ransomNote, string magazine) {
  int letterCount[26] = {0};
  for (char i : magazine) {
    ++letterCount[i - 'a'];
  }

  for (char i : ransomNote) {
    if (letterCount[i - 'a']--) {
      continue;
    } else {
      return false;
    }
  }

  return true;
}
