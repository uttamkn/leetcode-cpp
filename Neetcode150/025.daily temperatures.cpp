#include "../macros.h"
using namespace std;

class Solution {
public:
  vector<int> dailyTemperatures(vector<int> &temperatures) {
    stack<pair<int, int>> stk;
    int n = temperatures.size();

    vector<int> ans(n);

    for (int i = n - 1; i >= 0; --i) {
      while (!stk.empty() && stk.top().first <= temperatures[i]) {
        stk.pop();
      }

      if (!stk.empty()) {
        ans[i] = stk.top().second - i;
      }
      stk.push({temperatures[i], i});
    }
    return ans;
  }
};

int main() {
  Solution solution;
  return 0;
}
