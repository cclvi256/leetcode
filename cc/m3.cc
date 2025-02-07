#include <string>
#include <unordered_set>

int lengthOfLongestSubstring(std::string s) {
	auto it_left = s.cbegin(), it_right = s.cbegin();
	int max_length = 0;
	std::unordered_set<char> current_chars;

	while (it_right < s.cend()) {
		if (current_chars.find(*it_right) == current_chars.end()) {
			current_chars.insert(*it_right);
			++it_right;
			max_length = std::max(max_length, static_cast<int>(current_chars.size()));
		} else {
			current_chars.erase(*it_left);
			++it_left;
		}
	}

	return max_length;
}
