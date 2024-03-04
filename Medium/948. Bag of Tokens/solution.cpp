class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        if(tokens.size()==0) return 0;
        sort(tokens.begin(), tokens.end());
        if(power<tokens[0]) return 0;

        int score =0;
        int i=0, r=tokens.size()-1;
        while(i<=r) {
            if(power>=tokens[i]) {
                score++;
                power-=tokens[i];
                i++;
            }
            else {
                if(i==r) break;
                score--;
                power+=tokens[r];
                r--;
            }
        }

        return score;
    }
};