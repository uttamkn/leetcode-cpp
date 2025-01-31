#include "../macros.h"
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 1);

        int back = n - 1;
        int forward_prod = 1, backward_prod = 1;
        for(int front = 0; front < n; ++front) {
            result[front] *= forward_prod;
            result[back] *= backward_prod;

            forward_prod *= nums[front];
            backward_prod *= nums[back];
            back--;
        }

        return result;
    }
};

int main() {
  Solution solution;
  vector<int> nums = {1, 2, 4, 6};

  vector<int> res = solution.productExceptSelf(nums);

  dbg_vec(res)
  return 0;
}
