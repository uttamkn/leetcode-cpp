class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> freq_table(101, 0);
        for(int i=0; i<nums.size(); i++) {
             freq_table[nums[i]]++;
        }
        int max_freq=0, count_of_max_freq=1;
        for(int i=1; i<=100; i++) {
            if(freq_table[i]>max_freq) {
                max_freq=freq_table[i];
                count_of_max_freq=1;
            }
            else if((freq_table[i]==max_freq)&&(max_freq!=0)) count_of_max_freq++;
        }

        return max_freq*count_of_max_freq;
    }
};