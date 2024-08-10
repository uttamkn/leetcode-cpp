#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  double findMaxAverage(vector<int> &nums, int k) {
    signed int cur_sum = 0;
    double max_avg = (double)INT_MIN; // DBL_MIN is 0 so cant use that

    for (int i = 0; i < nums.size(); ++i) {
      cur_sum += nums[i];

      if (i >= (k - 1)) {
        max_avg = max(max_avg, (cur_sum / (double)k));
        cur_sum -= nums[i - k + 1];
      }
    }

    return max_avg;
  }
};

int main() {

  Solution solution;
  vector<int> nums = {1, 12, -5, -6, 50, 3};
  int k = 4;
  cout << solution.findMaxAverage(nums, k) << endl;

  return 0;
}
