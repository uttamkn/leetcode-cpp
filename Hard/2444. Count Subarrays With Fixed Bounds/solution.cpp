class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long int ans=0;
        int mini=-1, maxi=-1;
        for(int start=0, end=0; end<nums.size(); end++) {
            if(nums[end]<minK || nums[end]>maxK) {
                start=end+1;
                continue;
            } 
            if(nums[end]==maxK) maxi=end;
            if(nums[end]==minK) mini=end;
            ans+=max((min(maxi, mini)-start+1), 0);
        }
        return ans;
    }
};