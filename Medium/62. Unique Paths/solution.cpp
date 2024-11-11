#include <bits/stdc++.h>

class Solution {
public:
  int uniquePaths(int m, int n) {
    std::vector<std::vector<int>> dp(m + 1, std::vector(n + 1, -1));

    return solve(m, n, dp);
  }

private:
  int solve(int m, int n, std::vector<std::vector<int>> &dp) {
    if (m == 1 || n == 1)
      dp[m][n] = 1;

    if (dp[m][n] == -1) {
      dp[m][n] = solve(m - 1, n, dp) + solve(m, n - 1, dp);
    }

    return dp[m][n];
  }
};

int main() {
  Solution solution;
  std::cout << solution.uniquePaths(3, 7) << std::endl;
  return 0;
}
