#include "../macros.h"
#include <unordered_set>
#include <vector>
using namespace std;

// O(nlogn) because of sorting
// class Solution {
// public:
//   int longestConsecutive(vector<int> &nums) {
//
//     int n = nums.size();
//     if (n == 0)
//       return 0;
//     sort(nums.begin(), nums.end());
//
//     int cur_seq = 1, max_seq = 0;
//     for (int i = 0; i < n - 1; ++i) {
//       int diff = nums[i + 1] - nums[i];
//       if (diff == 1) {
//         cur_seq++;
//       } else if (diff != 0) {
//         max_seq = max(max_seq, cur_seq);
//         cur_seq = 1;
//       }
//     }
//
//     return max(max_seq, cur_seq);
//   }
// };

// O(n) but the above solution gave me a better time in leetcode for some reason
class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    unordered_set<int> set(nums.begin(), nums.end());
    int max_seq = 0;
    for (int num : set) {
      // if the number is the start of the sequence (rare case)
      if (set.find(num + 1) == set.end()) {
        int cur_seq = 1, cur_num = num;

        while (set.find(cur_num - 1) != set.end()) {
          cur_num--;
          cur_seq++;
        }

        max_seq = max(max_seq, cur_seq);
      }
    }

    return max_seq;
  }
};

int main() {
  Solution solution;
  vector<int> nums = {0,3,7,2,5,8,4,6,0,1};
  int res = solution.longestConsecutive(nums);
  dbg(res)

  return 0;
}
