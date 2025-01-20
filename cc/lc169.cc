#include <algorithm>
#include <random>
#include <vector>

bool isMajorityElement(std::vector<int> &nums, int target) {
  std::size_t count = 0;
  for (int i : nums) {
    if (i == target) {
      ++count;
    }
  }
  return count > nums.size() / 2;
}

int majorityElement(std::vector<int> &nums) {
  if (nums.size() < 20) {
    std::sort(nums.begin(), nums.end());
    return nums.at(nums.size() / 2);
  }

  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int> dist(0, nums.size() - 1);

  while (1) {
    std::size_t random_val1 = nums.at(dist(gen));
    std::size_t random_val2 = nums.at(dist(gen));
    std::size_t random_val3 = nums.at(dist(gen));
    if (random_val1 == random_val2 && random_val1 == random_val3) {
      if (isMajorityElement(nums, random_val1)) {
        return random_val1;
      }
    } else if (random_val1 == random_val2) {
      if (isMajorityElement(nums, random_val1)) {
        return random_val1;
      }
    } else if (random_val1 == random_val3) {
      if (isMajorityElement(nums, random_val1)) {
        return random_val1;
      }
    } else if (random_val2 == random_val3) {
      if (isMajorityElement(nums, random_val2)) {
        return random_val2;
      }
    } else {
      if (isMajorityElement(nums, random_val1)) {
        return random_val1;
      } else if (isMajorityElement(nums, random_val2)) {
        return random_val2;
      } else if (isMajorityElement(nums, random_val3)) {
        return random_val3;
      }
    }
  }
}
