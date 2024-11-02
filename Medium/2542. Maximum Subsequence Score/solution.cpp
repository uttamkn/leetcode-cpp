#include <algorithm>
#include <bits/stdc++.h>

class Solution {
public:
  long long maxScore(std::vector<int> &nums1, std::vector<int> &nums2, int k) {
    std::vector<std::pair<int, int>> vec;
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    int n = nums1.size();
    long long score = 0;

    for (int i = 0; i < n; ++i)
      vec.push_back({nums2[i], nums1[i]});

    std::sort(vec.rbegin(), vec.rend());

    long sum = 0;
    for (int i = 0; i < n; ++i) {
      auto &[num2, num1] = vec[i];
      minHeap.push(num1);
      sum += num1;

      if (minHeap.size() > k) {
        sum -= minHeap.top();
        minHeap.pop();
      }

      if (minHeap.size() == k)
        score = std::max(score, (long long)sum * num2);
    }
    return score;
  }
};

int main() {
  Solution solution;
  return 0;
}
