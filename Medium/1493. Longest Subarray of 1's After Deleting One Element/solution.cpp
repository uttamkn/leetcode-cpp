class Solution {
public:
  int longestSubarray(vector<int> &nums) {
    int start = 0, num_of_zeroes = 0, longestSubarr = 0;

    for (int end = 0; end < nums.size(); ++end) {
      if (nums[end] == 0)
        num_of_zeroes++;

      while (num_of_zeroes > 1) {
        if (nums[start++] == 0)
          num_of_zeroes--;
      }

      longestSubarr = max(longestSubarr, end - start);
    }

    return longestSubarr;
  }
};
