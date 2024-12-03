#include <bits/stdc++.h>

// 1. Memoization (recursion) solution. (need stack space + O(n)) Top-down
// int solve(int n, int k, std::vector<int> &heights, std::vector<int> &dp) {
//   if (n <= 0)
//     return 0;
//
//   if (dp[n] != -1)
//     return dp[n];
//
//   int min_val = INT_MAX;
//
//   for (int i = 1; i <= k && i <= n; ++i) {
//     min_val = std::min(solve(n - i, k, heights, dp) +
//                            abs(heights[n] - heights[n - i]),
//                        min_val);
//   }
//
//   dp[n] = min_val;
//
//   return dp[n];
// }

int frogKJump(int n, int k, std::vector<int> &heights) {
  if (k == 0)
    return 0;

  std::vector<int> dp(n, -1);

  if (k >= n)
    k = n - 1;

  // return solve(n - 1, k, heights, dp);

  // 2. Tabulation solution. (no need of stack space here) Bottom-up approach
  dp[0] = 0;
  for (int i = 1; i < n; i++) {
    int min_val = INT_MAX;
    for (int j = 1; j <= k && j <= i; ++j) {
      min_val = std::min(dp[i - j] + abs(heights[i] - heights[i - j]), min_val);
    }
    dp[i] = min_val;
  }

  return dp[n - 1];
}

int main() {
  int n = 4;
  int k = 2;
  std::vector<int> heights({10, 20, 30, 10});
  std::cout << frogKJump(n, k, heights) << std::endl;
  return 0;
}
