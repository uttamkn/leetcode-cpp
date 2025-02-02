#include <vector>
using namespace std;

class Solution {
public:
  int maxArea(vector<int> &heights) {
    int n = heights.size();
    int i = 0, j = n - 1;
    int max_area = 0;
    while (i < j) {
      int cur_area = (j - i) * min(heights[i], heights[j]);
      max_area = max(cur_area, max_area);

      if (heights[i] < heights[j]) {
        i++;
      } else {
        j--;
      }
    }

    return max_area;
  }
};

int main() {
  Solution solution;
  return 0;
}
