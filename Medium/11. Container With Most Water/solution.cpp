class Solution {
public:
    int maxArea(vector<int>& height) {
      int res = 0;
      int n = height.size();
      int i = 0, j = n - 1;
      while (i < j) {
        int cur_area = (j - i)*min(height[i], height[j]);
        res = max(res, cur_area);
        if(height[i] < height[j]) {
          i++;
        } else {
          j--;
        }
      }
      return res;
    }
};
