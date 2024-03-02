class Solution {
public:
    int lengthOfLastWord(string s) {
        istringstream iss(s);
        string word, last_word;
        while(getline(iss, word, ' ')) {
            if(!word.empty()) last_word=word;
        }

        return last_word.size();
    }
};