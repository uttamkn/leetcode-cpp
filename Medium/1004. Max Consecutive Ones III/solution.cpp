class Solution {
public:
  int longestOnes(vector<int> &nums, int k) {
    int max_ones = 0, cost = k, start = 0;

    for (int end = 0; end < nums.size(); ++end) {
      if (nums[end] == 0)
        cost--;

      while (cost == -1 && start <= end)
        if (nums[start++] == 0)
          cost++;

      max_ones = max(max_ones, end - start + 1);
    }

    return max_ones;
  }
};
