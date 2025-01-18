#include <vector>

int removeDuplicates(std::vector<int> &nums) {
  auto itr = nums.cbegin();
  auto itw = nums.begin();

	while (itr != nums.cend()) {
		*itw = *itr;
		while (itr != nums.cend() && *itr == *itw) {
			++itr;
		}
		++itw;
	}

	return itw - nums.begin();
}