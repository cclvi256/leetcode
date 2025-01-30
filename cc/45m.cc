#include <vector>

int jump(std::vector<int> &nums) {
  auto it_current_farthest = nums.cbegin();
  auto it_farthest = nums.cbegin();
  int step = 0;

  for (auto it = nums.cbegin(); it < nums.cend() - 1; ++it) {
    it_farthest = std::max(it_farthest, it + *it);
    if (it == it_current_farthest) {
      it_current_farthest = it_farthest;
      ++step;
    }
  }

  return step;
}
