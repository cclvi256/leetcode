#include <string>

std::string convert(std::string s, int numRows) {
	if (numRows == 1) {return s;}

	int period = 2 * numRows - 2;
	std::string result = "";

	for (int i = 0; i < s.size(); i += period) {
		result += s[i];
	}

	for (int i = 1; i < numRows - 1; i++) {
		for (int j = 0; j < s.size(); j += period) {
			if (j + i < s.size()) {
				result += s[j + i];
			}
			if (j + period - i < s.size()) {
				result += s[j + period - i];
			}
		}
	}

	for (int i = numRows - 1; i < s.size(); i += period) {
		result += s[i];
	}

	return result;
}
