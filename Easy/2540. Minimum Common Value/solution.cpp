class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        for(int num1 : nums1) {
            int mid=(nums2.size()-1)/2, low=0, high=nums2.size()-1;
            while(low<=high) {
                if(num1==nums2[mid]) return num1;
                if(num1>nums2[mid]) {
                    low=mid+1;
                }
                else {
                    high=mid-1;
                }
                mid=(low+high)/2;
            }
        }

        return -1;
    }
};