class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarrayWithAtMostKDistinct(nums, k) - subarrayWithAtMostKDistinct(nums, k-1);
    }

private:
    int subarrayWithAtMostKDistinct(vector<int>& nums, int k) {
        int start=0, distinctInts=0, count=0;
        unordered_map<int, int> map;
        for(int end=0; end<nums.size(); end++) {
            if(map[nums[end]]==0) distinctInts++;
            map[nums[end]]++;
            while(distinctInts>k) {
                map[nums[start]]--;
                if(map[nums[start]]==0) distinctInts--;
                start++;
            }
            count+=1+end-start;  
        }

        return count;
    }
};