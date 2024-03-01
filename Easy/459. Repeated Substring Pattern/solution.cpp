class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        if(s.substr(0, s.size()/2) == s.substr(s.size()/2)) return true;

        for(int substr_size=1; substr_size<s.size(); substr_size++) {

            int i=substr_size;
            while(i<s.size()) {
                if(s.substr(0, substr_size) != s.substr(i, substr_size)) break;
                else i+=substr_size;  
            }

            if(i==s.size()) return true;
        }

        return false;   
    }
};