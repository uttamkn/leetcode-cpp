#include "../macros.h"
using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    rep(i, 0, sz(nums) - 1) {
      rep(j, i, sz(nums)) {
        if (nums[i] + nums[j] == target) {
          return {i, j};
        }
      }
    }

    return {};
  }
};

int main() {
  Solution solution;
  return 0;
}
