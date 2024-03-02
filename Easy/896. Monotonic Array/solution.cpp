class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int isInc=0;
        if(nums[nums.size()-1]>nums[0]) isInc=1;
        else if(nums[nums.size()-1]==nums[0]) {
            for(int i=1; i<nums.size(); i++) {
                if(nums[i-1]!=nums[i]) return false;
            }
            return true;
        }
        for(int i=1; i<nums.size(); i++) {
            if(isInc) {
                if(nums[i-1]>nums[i]) return false;
            }
            else {
                if(nums[i-1]<nums[i]) return false;
            }
        }

        return true;
    }
};