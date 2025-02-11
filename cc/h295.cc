#include <queue>

class MedianFinder {
private:
  std::priority_queue<double, std::vector<double>, std::greater<double>>
      min_heap;
  std::priority_queue<double> max_heap;

public:
  MedianFinder() {}

  void addNum(int num) {
    if (max_heap.empty() || num <= max_heap.top()) {
      max_heap.push(num);
    } else {
      min_heap.push(num);
    }

    if (max_heap.size() > min_heap.size() + 1) {
      min_heap.push(max_heap.top());
      max_heap.pop();
    } else if (min_heap.size() > max_heap.size()) {
      max_heap.push(min_heap.top());
      min_heap.pop();
    }
  }

  double findMedian() {
    if (max_heap.size() == min_heap.size()) {
      return (max_heap.top() + min_heap.top()) / 2.0;
    } else {
      return max_heap.top();
    }
  }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */