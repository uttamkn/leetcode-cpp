#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int trap(vector<int> &height) {
    int n = height.size(), i = 0;

    if (n < 3)
      return 0;

    while (height[i] == 0)
      i++;

    int j = i + 1;
    int total_water = 0;
    while (j < n) {
      int cur_water = 0;
      while (j < n && height[j] < height[i]) {
        cur_water += height[i] - height[j];
        j++;
      }

      if (j >= n)
        break;

      if (height[j] >= height[i]) {
        total_water += cur_water;
        i = j;
        j++;
      }
    }

    // same thing but in reverse till the last peak (i)
    j = n - 1;
    int k = j - 1;

    while (k >= i) {
      int cur_water = 0;

      while (k >= i && height[k] < height[j]) {
        cur_water += height[j] - height[k];
        k--;
      }

      if (k < i)
        break;

      if (height[k] >= height[j]) {
        total_water += cur_water;
        j = k;
        k--;
      }
    }

    return total_water;
  }
};

int main() {
  Solution solution;
  vector<int> heights = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

  int res = solution.trap(heights);

  cout << res << endl;
  return 0;
}
