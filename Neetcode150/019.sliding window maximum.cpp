#include "../macros.h"
using namespace std;

class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    int n = nums.size();
    priority_queue<pair<int, int>> cur_win;
    vector<int> res;

    for (int i = 0; i < n; ++i) {
      cur_win.push({nums[i], i});

      if (i >= k - 1) {
        while (cur_win.top().second < i - k + 1)
          cur_win.pop();
        res.push_back(cur_win.top().first);
      }
    }

    return res;
  }
};

int main() {
  Solution solution;
  return 0;
}
