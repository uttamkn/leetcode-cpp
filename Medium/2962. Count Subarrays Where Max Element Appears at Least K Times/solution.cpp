class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long int max= *max_element(nums.begin(),nums.end());
        long long int max_count=0;
        long long int len=nums.size();
        long long int startWindow=0;
        long long int ans=0;
        for(long long int endWindow=0; endWindow<len; endWindow++) {
            if(nums[endWindow]==max) max_count++;
            while(max_count>=k) {
                ans+=len-endWindow;
                if(nums[startWindow]==max) max_count--;
                startWindow++;
            }
        }

        return ans;
    }
};