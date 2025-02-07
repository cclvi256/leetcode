#include <vector>

int canCompleteCircuit(std::vector<int> &gas, std::vector<int> &cost) {
  auto start = gas.cbegin();
  const int n = gas.size();

  while (start != gas.cend()) {
    int sum_gas = 0, sum_cost = 0;
    int count = 0;
    const int start_index = distance(gas.cbegin(), start);

    while (count < n) {
      int current_index = (start_index + count) % n;

      sum_gas += gas.at(current_index);
      sum_cost += cost.at(current_index);
			
      if (sum_cost > sum_gas)
        break;
      count++;
    }

    if (count == n) {
      return start_index;
    } else {
      int next_index = start_index + count + 1;
      start = (next_index < n) ? gas.cbegin() + next_index : gas.cend();
    }
  }
  return -1;
}