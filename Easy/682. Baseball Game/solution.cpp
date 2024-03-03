class Solution {
public:
    int calPoints(vector<string>& operations) {
        int sum=0;
        vector<int> nums;
        for(int i=0; i<operations.size(); i++) {
            if(operations[i]=="C") {
                sum-=nums[nums.size()-1];
                nums.pop_back();
                continue;
            }
            else if(operations[i]=="D") {
                nums.push_back(2*nums[nums.size()-1]);
                sum+=nums.back();
                continue;
            }
            else if(operations[i]=="+") {
                nums.push_back(nums[nums.size()-1]+nums[nums.size()-2]);
                sum+=nums.back();
                continue;
            }
            else {
                sum+=stoi(operations[i]);
                nums.push_back(stoi(operations[i]));
                continue;
            }
        }

        return sum;
    }
};