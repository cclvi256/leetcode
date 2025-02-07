#include <random>
#include <unordered_map>
#include <vector>

class RandomizedSet {
private:
  std::unordered_map<int, int> val2idx;
  std::vector<int> vals;
  std::default_random_engine rng;

public:
  RandomizedSet() {
    val2idx.clear();
    vals.clear();
    rng.seed(std::random_device()());
  }

  bool insert(int val) {
    if (val2idx.find(val) != val2idx.end()) {
      return false;
    }
    val2idx[val] = vals.size();
    vals.push_back(val);
    return true;
  }

  bool remove(int val) {
    if (val2idx.find(val) == val2idx.end()) {
      return false;
    }
    int idx = val2idx[val];
    val2idx[vals.back()] = idx;
    std::swap(vals[idx], vals.back());
    val2idx.erase(val);
    vals.pop_back();
    return true;
  }

  int getRandom() {
    std::uniform_int_distribution<int> dist(0, vals.size() - 1);
    int random_index = dist(rng);
    return vals[random_index];
  }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */