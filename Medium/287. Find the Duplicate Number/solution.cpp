class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int tortoise = nums[0];
        int hare = nums[0];

        while(true) {
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];

            if(hare == tortoise) break;
        }

        int ptr=nums[0];

        while(ptr!=tortoise) {
            ptr=nums[ptr];
            tortoise=nums[tortoise];
            if(ptr==tortoise) break;
        }

        return ptr;
    }
};