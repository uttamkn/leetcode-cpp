class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> h_table(26, 0);

        for(int i=0; i<order.size(); i++) {
            h_table[order[i]-97]=i+1;
        }
        char temp;
        for(int i=0; i<s.size(); i++) {
            for(int j=0; j<s.size()-i-1; j++) {
                if(h_table[s[j]-97]>h_table[s[j+1]-97]) {
                    temp = s[j];
                    s[j]=s[j+1];
                    s[j+1]=temp;
                }
            }
        }

        return s;
    }
};