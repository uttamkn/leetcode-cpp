#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

struct vectorHash {
  size_t operator()(const vector<int> &v) const {
    hash<int> int_hash;
    size_t seed = v.size();
    for (int i : v) {
      seed ^= int_hash(i) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    }
    return seed;
  }
};

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    unordered_set<vector<int>, vectorHash> set;

    for (int i = 0; i < n; ++i) {
      if (i != 0 && nums[i] == nums[i - 1])
        continue;
      int target = -nums[i];
      int j = i + 1;
      int k = n - 1;
      while (j < k) {
        if (i == j) {
          j++;
        } else if (i == k) {
          k--;
        } else {
          int sum = nums[j] + nums[k];

          if (sum < target) {
            j++;
          }

          if (sum > target) {
            k--;
          }

          if (sum == target) {
            vector<int> temp = {nums[i], nums[j], nums[k]};
            sort(temp.begin(), temp.end());
            set.insert(temp);
            j++;
            k--;
          }
        }
      }
    }

    vector<vector<int>> res;
    for (const auto num : set) {
      res.push_back(num);
    }

    return res;
  }
};

int main() {
  Solution solution;
  vector<int> nums = {-1, 0, 1, 2, -1, -4};
  vector<vector<int>> res = solution.threeSum(nums);
  for (const auto &v : res) {
    for (int x : v) {
      cout << x << " ";
    }
    cout << endl;
  }
  return 0;
}
