#include <vector>

template <typename Iter> void reverse(Iter first, Iter last) {
  while (first < last) {
    std::iter_swap(first++, --last);
  }
}

void rotate(std::vector<int> &nums, int k) {
  k %= nums.size();
  reverse(nums.begin(), nums.end());
  reverse(nums.begin(), nums.begin() + k);
  reverse(nums.begin() + k, nums.end());
}
