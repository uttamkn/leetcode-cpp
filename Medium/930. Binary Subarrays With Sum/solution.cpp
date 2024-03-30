class Solution {
public:
    int numSubarraysWithSumAtMostK(vector<int>& nums, int goal) {
        int n=nums.size();
        int start=0;
        int sum=0;
        int count=0;
        for(int end=0;end<n;end++){
            sum+=nums[end];
            while(start<=end && sum>goal){
                sum=sum-nums[start];
                start++;
            }
            count=count+(end-start+1);
        }
        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return numSubarraysWithSumAtMostK(nums, goal) - numSubarraysWithSumAtMostK(nums, goal-1); 
        }
};

//Brute Solution

  // int n=nums.size();
        // int c=0;
        // int count=0;
        // for(int i=0;i<n;i++){
        //     int sum=nums[i];
        //     for(int j=i+1;j<=n;j++){
        //         if(sum==goal) count++;
        //         sum+=nums[j];
        //     }
        // }
        // return count;