class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> h_table(1001, -1);
        vector<int> res;
        for(int num1 : nums1) {
            h_table[num1]=num1;
        }

        for(int num2 : nums2) {
            if(h_table[num2]==num2) h_table[num2]=-2;
        }

        for(int i=0; i<h_table.size(); i++) {
            if(h_table[i]==-2) res.push_back(i);
        }

        return res;
    }
};