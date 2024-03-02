class Solution {
public:
    int romanToInt(string s) {

        int res=charToInt(s[s.size()-1]);

        for(int i=s.size()-1; i>0; i--) {

            if(charToInt(s[i]) <= charToInt(s[i-1])) {
                res+=charToInt(s[i-1]);
            }
            else {
                res-=charToInt(s[i-1]);
            }

        }

        return res;
    }
private:
    int charToInt(char ch) {
        switch(ch) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return -1;
        }
    }
};