#include <vector>

int candy(std::vector<int> &ratings) {
	int res = 1;
	int increasing_seq = 1, decreasing_seq = 0, previous = 1;
	for (auto it = ratings.cbegin() + 1; it != ratings.cend(); ++it) {
		if (*it >= *(it - 1)) {
			decreasing_seq = 0;
			previous = *it == *(it - 1) ? 1 : previous + 1;
			res += previous;
			increasing_seq = previous;
		} else {
			++decreasing_seq;
			if (decreasing_seq == increasing_seq) {
				++decreasing_seq;
			}
			res += decreasing_seq;
			previous = 1;
		}
	}
	return res;
}
