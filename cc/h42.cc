#include <vector>

int trap(std::vector<int> &height) {
  auto it_left = height.cbegin(), it_right = height.cend() - 1;
  int left_max = 0, right_max = 0;

	int res = 0;

	while (it_left < it_right) {
		left_max = std::max(left_max, *it_left);
		right_max = std::max(right_max, *it_right);

		if (*it_left < *it_right) {
			res += left_max - *it_left;
			++it_left;
		} else {
			res += right_max - *it_right;
			--it_right;
		}
	}

	return res;
}