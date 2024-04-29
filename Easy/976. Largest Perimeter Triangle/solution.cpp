class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int max_perimeter=0;
        for(int i=nums.size()-1; i>=2; i--) {
            if(nums[i]<nums[i-1]+nums[i-2]) max_perimeter=max(max_perimeter, nums[i]+nums[i-1]+nums[i-2]);
        }
        return max_perimeter;
    }
};