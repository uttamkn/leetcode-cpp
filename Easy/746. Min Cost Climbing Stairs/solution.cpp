#include <bits/stdc++.h>

class Solution {
public:
  int minCostClimbingStairs(std::vector<int> &cost) {
    int n = cost.size();
    std::vector<int> dp(n, -1);
    return std::min(solve(cost, n - 1, dp), solve(cost, n - 2, dp));
  }

private:
  int solve(std::vector<int> &cost, int i, std::vector<int> &dp) {
    if (i < 0)
      return 0;
    if (i <= 1)
      return cost[i];

    if (dp[i] != -1)
      return dp[i];

    dp[i] = cost[i] + std::min(solve(cost, i - 1, dp), solve(cost, i - 2, dp));

    return dp[i];
  }
};

int main() {
  Solution solution;
  std::vector<int> cost = {10, 15, 20};
  std::cout << solution.minCostClimbingStairs(cost) << std::endl;
  return 0;
}
