#include <vector>

bool canJump(std::vector<int> &nums) {
  auto max = nums.cbegin();

  for (auto i = nums.cbegin(); i != nums.cend(); ++i) {
    if (i > max) {
      return false;
    }
    max = std::max(max, i + *i);
  }

  return true;
}
