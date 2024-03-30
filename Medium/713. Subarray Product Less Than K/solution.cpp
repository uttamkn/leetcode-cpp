class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int startWindow=0, count=0, windowProduct=1;
        if(k<=1) return 0;
        for(int endWindow=0; endWindow<nums.size(); endWindow++) {
            windowProduct*=nums[endWindow];
            while(windowProduct>=k) {
                windowProduct/=nums[startWindow++];
            }
            count+=1+endWindow-startWindow;
        }
        return count;
    }
};