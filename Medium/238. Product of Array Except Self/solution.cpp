class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(), 1); // Initialize ans with all 1s
        
        // Calculate left products
        int left_prod = 1;
        for(int i = 0; i < nums.size(); i++) {
            ans[i] *= left_prod;
            left_prod *= nums[i];
        }
        
        // Calculate right products
        int right_prod = 1;
        for(int i = nums.size() - 1; i >= 0; i--) {
            ans[i] *= right_prod;
            right_prod *= nums[i];
        }
        
        return ans;
    }
};
