#include <bits/stdc++.h>

class Solution {
public:
  int rob(std::vector<int> &nums) {
    int n = nums.size();
    std::vector<int> dp(n, -1);

    return std::max(solve(nums, n - 1, dp), solve(nums, n - 2, dp));
  }

private:
  int solve(std::vector<int> &nums, int i, std::vector<int> &dp) {
    if (i < 0)
      return 0;

    if (i <= 1)
      return nums[i];

    if (dp[i] != -1)
      return dp[i];

    dp[i] = nums[i] + std::max(solve(nums, i - 2, dp), solve(nums, i - 3, dp));

    return dp[i];
  }
};

int main() {
  Solution solution;
  std::vector<int> nums = {8, 2, 2, 8};

  std::cout << solution.rob(nums) << std::endl;
  return 0;
}
