#include <bits/stdc++.h>
using namespace std;

// 1. Memoization (recursion) solution. (need stack space + O(n)) Top-down
int solve(int n, vector<int> &heights, vector<int> &dp) {
  if (n == 0)
    return 0;
  if (n == 1)
    return abs(heights[1] - heights[0]);

  if (dp[n] != -1)
    return dp[n];

  dp[n] = min(solve(n - 1, heights, dp) + abs(heights[n] - heights[n - 1]),
              solve(n - 2, heights, dp) + abs(heights[n] - heights[n - 2]));

  return dp[n];
}

int frogJump(int n, vector<int> &heights) {
  vector<int> dp(n, -1);
  // return solve(n-1, heights, dp);

  // 2. Tabulation solution. (no need of stack space here) Bottom-up approach
  // dp[0] = 0;
  // dp[1] = abs(heights[0] - heights[1]);

  // for(int i = 2; i < n; ++i) {
  //     dp[i] = min(dp[i-1] + abs(heights[i] - heights[i-1]), dp[i-2] +
  //     abs(heights[i] - heights[i-2]));
  // }

  // return dp[n-1];

  // 3. Space optimized solution (O(1) space) Bottom-up approach
  int prev2 = 0, prev1 = 0, cur = 0;

  for (int i = 1; i < n; i++) {
    int first_step = prev1 + abs(heights[i] - heights[i - 1]);
    int second_step = INT_MAX;
    if (i > 1)
      second_step = prev2 + abs(heights[i] - heights[i - 2]);

    cur = min(first_step, second_step);
    prev2 = prev1;
    prev1 = cur;
  }
  return cur;
}

int main() {
  int n = 4;
  vector<int> heights({10, 20, 30, 10});
  cout << frogJump(n, heights) << endl;
  return 0;
}
