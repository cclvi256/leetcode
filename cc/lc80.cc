#include <optional>
#include <vector>

int removeDuplicates(std::vector<int> &nums) {
  auto itr = nums.cbegin();
  auto itw = nums.begin();

  std::optional<int> prev = std::nullopt;
  int status = 0;

  while (itr != nums.cend()) {
    if (!prev.has_value() || prev.value() != *itr) {
      prev = *itr;
      status = 1;
    } else {
      ++status;
    }

    if (status <= 2) {
      *itw = *itr;
      ++itw;
    }

    ++itr;
  }

	return itw - nums.begin();
}