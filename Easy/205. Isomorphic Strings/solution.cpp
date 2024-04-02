class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> hmap;
        unordered_map<char, char> hmap2;
        int i=0;
        for(char ch : s) {
            if(hmap.find(ch)!=hmap.end()) {
                if(hmap[ch]!=t[i]) return false;
            }
            else {
                hmap[ch]=t[i];
                if(hmap2.find(t[i])!=hmap2.end()) {
                    return false;
                }
                else hmap2[t[i]]=ch;
            }
            i++;
        }
        return true;
    }
};