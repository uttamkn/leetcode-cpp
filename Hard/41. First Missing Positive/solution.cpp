class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i;
        for(i=0; i<nums.size(); i++) {
            if(nums[i]>=1) break;
        }
        int ans=1;
        if(i==nums.size() || nums[i]>1) return 1; 
        while(i<nums.size()) {
            if(nums[i]==ans) {
                i++;
                continue;
            }
            else {
                ans++;
                if(nums[i]!=ans) return ans;
                i++;
            }
        }

        return ans+1;
    }
};