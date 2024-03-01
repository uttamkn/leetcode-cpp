#include<iostream>
#include<strstream>
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