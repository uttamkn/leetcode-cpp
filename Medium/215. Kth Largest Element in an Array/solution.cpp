#include <bits/stdc++.h>

// https://github.com/uttamkn/dsa-in-C/blob/main/queue/priority_queue.c
class Solution {
public:
  int findKthLargest(std::vector<int> &nums, int k) {
    std::priority_queue<int> pq;

    for (int num : nums) {
      pq.push(num);
    }

    for (int i = 0; i < k - 1; ++i) {
      pq.pop();
    }

    return pq.top();
  }
};

int main() {
  Solution solution;
  return 0;
}
