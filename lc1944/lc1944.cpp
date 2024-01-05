#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> canSeePersonsCount(vector<int>& heights);

int main(int argc, char** argv) {}

vector<int> canSeePersonsCount(vector<int>& heights) {
  heights.push_back(0);

  vector<int> result;
  int count = heights.size();
  stack<int> st;

  size_t stack_size = 0;

  for (int i = count - 1; i > 0; --i) {
    
  }
}