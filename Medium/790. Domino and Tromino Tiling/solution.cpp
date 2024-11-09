#include <bits/stdc++.h>

class Solution {
public:
  int numTilings(int n) {
    std::vector<int> dp(n + 1, -1);
    return solve(n, dp);
  }

private:
  int solve(int n, std::vector<int> &dp) {
    if (n <= 1)
      return 1;

    if (n == 2)
      return 2;

    if (dp[n] == -1) {
      dp[n] = (2 * solve(n - 1, dp)) % 1000000007 + solve(n - 3, dp);
    }

    return dp[n] % 1000000007;
  }
};

int main() {
  Solution solution;
  std::cout << solution.numTilings(3) << std::endl;
  return 0;
}
