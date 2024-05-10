#include<iostream>
#include<sstream>
#include<stack>
#include<string>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        istringstream iss(s);
        string token;
        stack<string> temp;
        string res;
        while(getline(iss, token, ' ')) {
            if(!token.empty()) {
                temp.push(token);
            }
        }

        while(!temp.empty()){
            res.append(temp.top());
            res.append(" ");
            temp.pop();
        }

        res.erase(res.size()-1);
        return res;
    }
};

//O(1) space complexity
class Solution {
public:
    string reverseWords(string s) {
        s=trim(s);
        reverse(s.begin(), s.end());
        istringstream iss(s);
        string token;
        size_t pos=0;
        while(getline(iss, token, ' ')) {
            if(!token.empty()) {
                pos=s.find(token, pos);
                reverse(token.begin(), token.end());
                s.replace(pos, token.size(), token);
                pos++;
            }
            else { //if token is a null character (consecutive blank spaces)
                s.erase(s.find("  "), 1);
            }
        }
        return s;
    }

private:
    string trim(const string& str) {
        size_t first = str.find_first_not_of(' ');
        if (string::npos == first) {
            return "";
        }
        size_t last = str.find_last_not_of(' ');
        return str.substr(first, (last - first + 1));
    }
};