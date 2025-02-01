#include "../macros.h"
using namespace std;

class Solution {
public:
  int longestConsecutive(vector<int> &nums) {

    int n = nums.size();
    if (n == 0)
      return 0;
    sort(nums.begin(), nums.end());

    int cur_seq = 1, max_seq = 0;
    for (int i = 0; i < n - 1; ++i) {
      int diff = nums[i + 1] - nums[i];
      if (diff == 1) {
        cur_seq++;
      } else if (diff != 0) {
        max_seq = max(max_seq, cur_seq);
        cur_seq = 1;
      }
    }

    return max(max_seq, cur_seq);
  }
};

int main() {
  Solution solution;
  return 0;
}
