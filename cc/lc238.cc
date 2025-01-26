// #include <vector>

// std::vector<int> productExceptSelf(std::vector<int> &nums) {
//   std::vector<int> res(nums.size(), 1);

//   int pref_product = 1;
//   int suff_product = 1;

//   auto it_res_pref = res.begin() + 1;
//   auto it_res_suff = res.rbegin() + 1;
//   auto it_nums_pref = nums.cbegin();
//   auto it_nums_suff = nums.crbegin();

// 	while (it_res_pref < res.cend()) {
// 		pref_product *= *it_nums_pref;
// 		suff_product *= *it_nums_suff;

// 		*it_res_pref *= pref_product;
// 		*it_res_suff *= suff_product;

// 		++it_res_pref;
// 		++it_res_suff;
// 		++it_nums_pref;
// 		++it_nums_suff;
// 	}

// 	return res;
// }
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