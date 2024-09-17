#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int findPeakElement(vector<int> &nums) {
    int n = nums.size();
    int low = 0, high = n - 1;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if ((mid == 0 || nums[mid] > nums[mid - 1]) &&
          (mid == n - 1 || nums[mid] > nums[mid + 1]))
        return mid;
      else if (mid != 0 && nums[mid] < nums[mid - 1])
        high = mid - 1;
      else
        low = mid + 1;
    }
    return 0;
  }
};

int main() {
  Solution sol;
  vector<int> nums = {1, 2, 1, 3, 5, 6, 4};
  cout << sol.findPeakElement(nums) << endl;
  return 0;
}
