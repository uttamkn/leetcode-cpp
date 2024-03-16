class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int tmp_sum=0,ans=0;
        unordered_map<int, int> p_sum;
        p_sum[0]=-1;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i]==1) tmp_sum++;
            else tmp_sum--;
            if(p_sum.find(tmp_sum)!=p_sum.end()) {
                if(i-p_sum[tmp_sum]>ans) ans=i-p_sum[tmp_sum];
                else continue;
            }
            else p_sum[tmp_sum]=i;
        }

        return ans;
    }
};