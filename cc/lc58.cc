#include <string>

int lengthOfLastWord(std::string s) {
	int len = 0;
	for (auto it = s.rbegin(); it != s.rend(); ++it) {
		if (*it == ' ') {
			if (len > 0) {
				break;
			}
		} else {
			++len;
		}
	}

	return len;
}