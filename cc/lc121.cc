#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int> &prices);

int maxProfit(vector<int> &prices) {
  int n = prices.size();
  if (n == 0) {
    return 0;
  }

  int minPrice = prices[0];
  int maxProfit = 0;

  for (int i = 1; i < n; i++) {
    if (prices[i] < minPrice) {
      minPrice = prices[i];
    } else {
      maxProfit = max(maxProfit, prices[i] - minPrice);
    }
  }

  return maxProfit;
}

int main(int argc, char **argv) {
  int n;
  cout << "Enter the number of days: ";
  cin >> n;

  vector<int> prices;
  cout << "Enter the prices of the stock for each day: " << endl;
  for (int i = 0; i < n; i++) {
    int price;
    cin >> price;
    prices.push_back(price);
  }

  int maxProfitValue = maxProfit(prices);

  cout << "Max Profit: " << maxProfitValue << endl;

  return 0;
}
