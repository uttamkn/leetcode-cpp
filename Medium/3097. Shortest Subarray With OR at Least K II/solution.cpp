#include <bits/stdc++.h>

class Solution {
public:
  int minimumSubarrayLength(std::vector<int> &nums, int k) {
    int n = nums.size();

    int start_win = 0, end_win;
    int curr_bit_or = 0;

    int bits[32];
    memset(bits, 0, sizeof bits);

    int min_len = INT_MAX;

    for (int end_win = 0; end_win < n; end_win++) {
      curr_bit_or |= nums[end_win];
      addBitFrequency(nums[end_win], bits);

      while (start_win <= end_win && curr_bit_or >= k) {
        min_len = std::min(min_len, end_win - start_win + 1);

        curr_bit_or -= minusBitFrequency(nums[start_win++], bits);
      }
    }

    return (min_len == INT_MAX) ? -1 : min_len;
  }

private:
  void addBitFrequency(int num, int *bits) {
    int i = 0;
    while (num > 0) {
      bits[i] += num % 2;
      num /= 2;
      i++;
    }
  }

  int minusBitFrequency(int num, int *bits) {
    int i = 0;
    int res = 0;
    while (num > 0) {

      if (bits[i] == 1 && num % 2 == 1) {
        res += std::pow(2, i);
        bits[i] -= 1;
        num /= 2;
        i++;
        continue;
      }

      bits[i] -= num % 2;
      num /= 2;
      i++;
    }

    return res;
  }
};

int main() {
  Solution solution;
  std::vector<int> nums = {2, 1, 8};
  std::cout << solution.minimumSubarrayLength(nums, 10);
  return 0;
}
