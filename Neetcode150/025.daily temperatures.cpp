#include "../macros.h"
using namespace std;

class Solution {
public:
  vector<int> dailyTemperatures(vector<int> &temperatures) {
    int n = temperatures.size();
    vector<int> ans(n);

    for (int i = 0; i < n - 1; i++) {
      for (int j = i + 1; j < n; ++j) {
        if (temperatures[j] > temperatures[i]) {
          ans[i] = j - i;
          break;
        }
      }
    }

    return ans;
  }
};

int main() {
  Solution solution;
  return 0;
}
