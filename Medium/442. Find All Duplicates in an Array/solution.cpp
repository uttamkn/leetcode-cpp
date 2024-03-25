// class Solution {
// public:
//     vector<int> findDuplicates(vector<int>& nums) {
//         sort(nums.begin(), nums.end());

//         int check=0;
//         vector<int> res;

//         for(int num : nums) {
//             if(num!=check) check=num;
//             else res.push_back(num);
//         }

//         return res;
//     }
// };

class Solution {
public:
    vector<int> findDuplicates(vector<int> & nums) {
        vector<int> res;
        for(int i=0; i<nums.size(); i++) {
            if(nums[abs(nums[i])-1]<0) res.push_back(abs(nums[i]));
            nums[abs(nums[i])-1]=0-nums[abs(nums[i])-1];
        }

        return res;
    }
};