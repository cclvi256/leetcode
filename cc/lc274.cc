#include <algorithm>
#include <vector>

int hIndex(std::vector<int>& citations) {
	std::size_t len = citations.size();
	std::vector<int> count(len + 1, 0);

	for (int entry : citations) {
		if (entry >= len) {
			count[len]++;
		} else {
			count[entry]++;
		}
	}

	int total = 0;
	for (std::size_t i = len; i >= 0; i--) {
		total += count[i];
		if (total >= i) {
			return i;
		}
	}

	return 0;
}

int hIndexAlt(std::vector<int>& citations) {
	std::sort(citations.begin(), citations.end(), std::greater<int>());

	for (std::size_t i = 0; i < citations.size(); i++) {
		if (citations[i] < i + 1) {
			return i;
		}
	}

	return citations.size();
}
