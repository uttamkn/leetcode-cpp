#include "../macros.h"
using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int n = prices.size(), cur_max = INT_MIN, cur_min = INT_MAX;

    int max_profit = 0;
    for (int i = 0; i < n; ++i) {
      if (prices[i] > cur_max)
        cur_max = prices[i];

      if (prices[i] < cur_min) {
        cur_max = prices[i];
        cur_min = prices[i];
      }

      max_profit = max(max_profit, cur_max - cur_min);
    }

    return max_profit;
  }
};

int main() {
  Solution solution;
  return 0;
}
