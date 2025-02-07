#include <vector>

int minSubArrayLen(int target, std::vector<int>& nums) {
	auto it_left = nums.cbegin(), it_right = nums.cbegin();
	int sum = 0, min_len = 0;

	while (it_right != nums.cend()) {
		sum += *it_right++;
		while (sum >= target) {
			int len = it_right - it_left;
			min_len = min_len == 0 ? len : std::min(min_len, len);
			sum -= *it_left++;
		}
	}

	return min_len;
}
