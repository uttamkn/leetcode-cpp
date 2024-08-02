//old code (rejected because O(n^2) complexity)
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int res = 0, n = nums.size();
        sort(nums.begin(), nums.end());
        int end = n - 1;
        for (;end >= 0 && nums[end] >= k; --end);

        for (int i = end; i > 0; --i) {
          int j = 0;
          while (j < i) {
            if(nums[j] == -1) {
              j++;
              continue;
            }

            int cur_sum = nums[i] + nums[j];

            if(cur_sum > k) break;

            if(cur_sum == k) {
              nums[j] = -1;
              res++;
              break;
            }

            j++;
          }
        }
        return res;
    }
};

//accepted code (O(nlogn) complexity)
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int res = 0, n = nums.size();
        sort(nums.begin(), nums.end());
        int i =0, j = n - 1;
        while (i < j) {
          int cur_sum = nums[i] + nums[j];

          if(cur_sum > k) {
            j--;
          } else if(cur_sum == k) {
              res++;
              j--;
              i++;
          } else {
            i++;
          }
        }

        return res;
    }
};

//In two pointer approach try to avoid multiple loops
