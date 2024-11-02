#include <bits/stdc++.h>

class Solution {
public:
  int trap(std::vector<int> &height) {
    int i = 0;
    int n = height.size();
    int area = 0;

    while (i < n && height[i] == 0)
      i++;

    int j = i + 1;

    while (j < n) {
      int b = 0;
      int temp = 0; // should be subtracted from the final area
      while (j < n && height[i] > height[j]) {
        temp += height[j];
        b++;
        j++;
      }

      if (j == n)
        break;

      if (height[j] >= height[i]) {
        area += (b * std::min(height[i], height[j])) - temp;
      }

      i = j++;
    }

    if (i != n) {
      // j will be n
      j--;
      while (j > i && height[j] == 0)
        j--;

      int ri = j - 1;

      while (ri >= i) {
        int b = 0;
        int temp = 0;
        while (ri >= i && height[j] > height[ri]) {
          temp += height[ri];
          b++;
          ri--;
        }

        if (ri < i)
          break;

        if (height[ri] >= height[j]) {
          area += (b * std::min(height[j], height[ri])) - temp;
        }

        j = ri--;
      }
    }

    return area;
  }
};

int main() {
  Solution solution;
  std::vector<int> in = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

  std::cout << solution.trap(in) << std::endl;
  return 0;
}
