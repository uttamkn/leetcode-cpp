#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string decodestring(string s) {
    stack<string> stk;
    stack<int> k;

    for (int i = 0; i < s.size(); ++i) {
      if (isdigit(s[i])) {
        int num = 0;
        while (isdigit(s[i])) {
          num = num * 10 + (s[i] - '0');
          i++;
        }
        k.push(num);
        string str(1, s[i]);
        stk.push(str);
      } else if (s[i] == ']') {
        string str1 = "", str2 = stk.top();
        while (!stk.empty() && stk.top() != "[") {
          str1 = str2.append(str1);
          stk.pop();
          if (!stk.empty())
            str2 = stk.top();
        }
        if (!stk.empty() && stk.top() == "[")
          stk.pop(); // remove '['

        string newStr = str1;
        for (int i = 0; i < k.top() - 1; ++i)
          newStr.append(str1);
        k.pop();

        stk.push(newStr);
      } else {
        string str(1, s[i]);
        stk.push(str);
      }
    }

    string str1 = "", str2 = stk.top();
    while (!stk.empty()) {
      str1 = str2.append(str1);
      stk.pop();
      if (!stk.empty())
        str2 = stk.top();
    }

    return str1;
  }
};

int main() {
  Solution sol;
  string s[] = {"3[a]2[bc]", "3[a2[c]]", "2[abc]3[cd]ef", "abc3[cd]xyz",
                "10[leetcode]"};
  if (sol.decodestring(s[0]) == "aaabcbc" &&
      sol.decodestring(s[1]) == "accaccacc" &&
      sol.decodestring(s[2]) == "abcabccdcdcdef" &&
      sol.decodestring(s[3]) == "abccdcdcdxyz" &&
      sol.decodestring(s[4]) == "leetcodeleetcodeleetcodeleetcodeleetcodeleetco"
                                "deleetcodeleetcodeleetcodeleetcode")
    cout << "All test cases passed!" << endl;
  return 0;
}
