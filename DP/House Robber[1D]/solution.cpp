#include "../../macros.h"

class Solution {
public:
  long long int houseRobber(vector<int> &valueInHouse) {
    int n = sz(valueInHouse);
    vi dp(n, -1);
    // return f(n - 1, valueInHouse, dp); // memoization (top-down approach(need stack space + O(n)))

    // Tabulation (bottom-up approach O(n) space)
    // dp[0] = valueInHouse[0];
    // for (int i = 1; i < n; ++i) {
    //   long long int pick = valueInHouse[i];
    //   if (i > 1)
    //     pick += dp[i - 2];
    //   long long int notPick = dp[i - 1];
    //
    //   dp[i] = max(pick, notPick);
    // }
    //
    // return dp[n - 1];

    // space optimization (O(1) space)
    long long int prev = valueInHouse[0];
    long long int prev2 = 0;

    for (int i = 1; i < n; ++i) {
      long long int pick = valueInHouse[i];
      if (i > 1)
        pick += prev2;

      long long int notPick = prev;

      long long int cur = max(pick, notPick);
      prev2 = prev;
      prev = cur;
    }

    return prev;
  }

private:
  // Memoization
  long long int f(int n, vector<int> &valueInHouse, vector<int> &dp) {
    if (n == 0)
      return valueInHouse[n];

    if (n < 0)
      return 0;

    if (dp[n] != -1)
      return dp[n];

    long long int pick = valueInHouse[n] + f(n - 2, valueInHouse, dp);
    long long int notPick = f(n - 1, valueInHouse, dp);

    return dp[n] = max(pick, notPick);
  }
};

int main() {
  Solution s;
  vector<int> valueInHouse = {6, 5, 4, 3};
  cout << s.houseRobber(valueInHouse) << endl;
  return 0;
}
