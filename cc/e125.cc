#include <string>

bool isPalindrome(std::string s) {
	auto it = s.cbegin();
	auto itr = s.cend() - 1;

	while (it < itr) {
		if (!std::isalnum(*it)) {
			++it;
		} else if (!std::isalnum(*itr)) {
			--itr;
		} else if (std::tolower(*it) != std::tolower(*itr)) {
			return false;
		} else {
			++it;
			--itr;
		}
	}

	return true;
}
