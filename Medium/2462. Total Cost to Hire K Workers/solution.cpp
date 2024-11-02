#include <bits/stdc++.h>

class Solution {
public:
  long long totalCost(std::vector<int> &costs, int k, int candidates) {
    int n = costs.size();
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                        std::greater<std::pair<int, int>>>
        left_minHeap;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                        std::greater<std::pair<int, int>>>
        right_minHeap;

    int front = 0, back = n - 1;

    while (front < candidates && back >= n - candidates && front <= back) {
      if (front == back) {
        left_minHeap.push({costs[front], front});
      } else {
        left_minHeap.push({costs[front], front});
        right_minHeap.push({costs[back], back});
      }

      front++;
      back--;
    }

    long long total = 0;
    for (int i = 0; i < k; ++i) {

      if (!right_minHeap.empty() &&
          (left_minHeap.empty() ||
           right_minHeap.top().first < left_minHeap.top().first)) {
        auto &[right_min, r_idx] = right_minHeap.top();
        total += right_min;
        right_minHeap.pop();
        if (front <= back) {
          right_minHeap.push({costs[back], back});
          back--;
        }
      } else {
        auto &[left_min, l_idx] = left_minHeap.top();
        total += left_min;
        left_minHeap.pop();
        if (front <= back) {
          left_minHeap.push({costs[front], front});
          front++;
        }
      }
    }

    return total;
  }
};

int main() {
  Solution solution;
  std::vector<int> costs = {17, 12, 10, 2, 7, 2, 11, 20, 8};
  int k = 3;
  int candidates = 4;

  std::cout << solution.totalCost(costs, k, candidates) << std::endl;
  return 0;
}
