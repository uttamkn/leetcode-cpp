class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int startWindow=0, ans=0;
        unordered_map <int, int> freq_table;
        for(int endWindow=0; endWindow<nums.size(); endWindow++) {
            freq_table[nums[endWindow]]++;
            while(freq_table[nums[endWindow]]>k) {
                freq_table[nums[startWindow++]]--;
            }
            ans=max(ans, (endWindow-startWindow)+1);
        }

        return ans;
    }
};