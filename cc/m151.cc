#include <string>

std::string reverseWords(std::string s) {
  std::string res;

  auto it_word = s.cbegin();
	auto it_letter = s.cbegin();

	while (it_letter != s.cend()) {
		if (*it_letter == ' ') {
			++it_letter;
			continue;
		}

		it_word = it_letter;
		while (it_letter != s.cend() && *it_letter != ' ') {
			++it_letter;
		}
		
		res.insert(res.cbegin(), it_word, it_letter);
		res.insert(res.cbegin(), ' ');
	}

	res.erase(res.cbegin());
	return res;
}