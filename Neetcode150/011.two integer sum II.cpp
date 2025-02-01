#include "../macros.h"
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &numbers, int target) {
    int n = numbers.size(), i = 0, j = n - 1;

    while (i < j) {
      int cur_sum = numbers[i] + numbers[j];

      if (cur_sum == target)
        return {i + 1, j + 1};

      if (cur_sum < target) {
        i++;
        continue;
      }

      if (cur_sum > target) {
        j--;
        continue;
      }

      i++;
      j--;
    }

    return {};
  }
};

int main() {
  Solution solution;
  vector<int> nums = {-1,0};
  int target = -1;
  vector<int> res = solution.twoSum(nums, target);
  dbg_vec(res)
  return 0;
}
