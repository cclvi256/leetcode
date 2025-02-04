#include <vector>

std::vector<int> productExceptSelf(std::vector<int> &nums) {
  const size_t n = nums.size();
  std::vector<int> res(n, 1);

  int prefix = 1;
  auto res_it = res.begin() + 1;
  auto num_it = nums.cbegin();
  for (; res_it != res.end(); ++res_it, ++num_it) {
    prefix *= *num_it;
    *res_it = prefix;
  }

  int suffix = 1;
  auto res_rit = res.rbegin() + 1;
	auto num_rit = nums.crbegin();
  for (; res_rit != res.rend(); ++res_rit, ++num_rit) {
    suffix *= *num_rit;
    *res_rit *= suffix;
  }

  return res;
}