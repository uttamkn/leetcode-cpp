#include <bits/stdc++.h>

class Solution {
public:
  int maxSubArray(std::vector<int> &nums) {
    int max_sum = INT_MIN, cur_sum = 0;
    int n = nums.size();
    int start_idx, end_idx; // to find the subarray with max sum

    for (int i = 0; i < n; ++i) {
      cur_sum += nums[i];

      if (cur_sum > max_sum) {
        max_sum = cur_sum;
        end_idx = i;
      }

      if (cur_sum < 0) {
        cur_sum = 0;
        start_idx = i + 1;
      }
    }

    for (int i = start_idx; i <= end_idx; ++i) {
      std::cout << nums[i] << " ";
    }

    std::cout << "\n";

    return max_sum;
  }
};

int main() {
  Solution solution;
  std::vector<int> x = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

  std::cout << solution.maxSubArray(x);
  return 0;
}
