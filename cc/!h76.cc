#include <string>
#include <unordered_map>

std::string minWindow(std::string s, std::string t) {
  // Step 1: Initialisation
  auto it_l = s.cbegin(), it_r = s.cbegin();
  std::unordered_map<char, int> count_map;
  for (const auto &c : t) {
    ++count_map.at(c);
  }

  // Step 2: Find the first window
	
}
