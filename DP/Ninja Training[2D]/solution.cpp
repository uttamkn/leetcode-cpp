#include "../../macros.h"

class Solution {
public:
  int ninjaTraining(int n, vector<vector<int>> &points) {
    // vvi dp(n, vi(4, -1));
    // return f(n - 1, points, 3, dp); // Memoization

    // Tabulation
    // rep(i, 0, 4) {
    //   int maxi = 0;
    //   rep(j, 0, 3) {
    //     if (j != i) {
    //       int pts = points[0][j];
    //       maxi = max(maxi, pts);
    //     }
    //   }
    //   dp[0][i] = maxi;
    // }
    //
    // rep(day, 1, n) {
    //   rep(j, 0, 4) {
    //     int maxi = 0;
    //     rep(k, 0, 3) {
    //       if (j != k) {
    //         int pts = points[day][k] + dp[day - 1][k];
    //         maxi = max(maxi, pts);
    //       }
    //     }
    //
    //     dp[day][j] = maxi;
    //   }
    // }
    //
    //
    // return dp[n-1][3];

    // Space optimization
    vi prev(4, -1);

    rep(i, 0, 4) {
      int maxi = 0;
      rep(j, 0, 3) {
        if(i != j) {
          maxi = max(maxi, points[0][j]);
        }
      }
      prev[i] = maxi;
    }

    rep(day, 1, n) {
      vi cur(4, -1);
      rep(i, 0, 4) {
        rep(j, 0, 3) {
          if(i!=j) {
            cur[i] = max(cur[i], points[day][j] + prev[j]); 
          }
        }
      }
      prev = cur;
    }

    return prev[3];
  }

private:
  // Memoization
  // int f(int day, vvi &points, int last, vvi &dp) {
  //   if (day < 0) {
  //     return 0;
  //   }
  //
  //   if (dp[day][last] != -1)
  //     return dp[day][last];
  //
  //   int maxi = 0;
  //   rep(i, 0, 3) {
  //     if (i != last) {
  //       int pts = points[day][i] + f(day - 1, points, i, dp);
  //       maxi = max(maxi, pts);
  //     }
  //   }
  //
  //   return dp[day][last] = maxi;
  // }
};

int main() {
  Solution s;
  int n = 3;
  vvi points = {{1, 2, 5}, {3, 1, 1}, {3, 3, 3}};
  cout << s.ninjaTraining(n, points) << endl;
}
