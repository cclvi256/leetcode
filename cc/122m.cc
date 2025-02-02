#include <vector>

int maxProfit(std::vector<int> &prices) {
  int profit = 0;
  for (std::size_t i = 1; i < prices.size(); i++) {
    if (prices[i] > prices[i - 1]) {
      profit += prices[i] - prices[i - 1];
    }
  }

  return profit;
}
