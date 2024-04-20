class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxWealth=0, curWealth;
        for(int i=0; i<accounts.size(); i++) {
            curWealth=0;
            for(int j=0;j<accounts[i].size(); j++) {
                curWealth+=accounts[i][j];
            }
            if(maxWealth<curWealth) maxWealth=curWealth;
        }

        return maxWealth;
    }
};