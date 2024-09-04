#include <bits/stdc++.h>
using namespace std;

// O(n) time and O(n) space using stack
class Solution {
public:
  string removeStars(string s) {
    stack<char> stk;
    for (char c : s) {
      if (!stk.empty() && c == '*')
        stk.pop();
      else if (c != '*')
        stk.push(c);
    }

    string res = "";

    // while (!stk.empty()) {
    //   res = stk.top() + res;
    //   stk.pop();
    // }
    // the above code constructs the final result by prepending characters from
    // the stack to an initially empty string. This approach is potentially
    // inefficient because strings in C++ are immutable, so concatenating a
    // character at the beginning of a string repeatedly can result in multiple
    // memory allocations and copies. leading to a memory limit exceeded error.

    // so we have to append the characters to the end of the string and then
    // reverse it
    while (!stk.empty()) {
      res.push_back(stk.top());
      stk.pop();
    }
    reverse(res.begin(), res.end());

    return res;
  }
};

// O(1) space and O(n squared) time
// class Solution {
// public:
//   string removeStars(string s) {
//     auto itr = s.end();
//     int pop_amt = 0;
//     while (itr >= s.begin()) {
//       while (itr >= s.begin() && pop_amt > 0) {
//         if (*itr == '*') {
//           pop_amt++;
//         } else {
//           pop_amt--;
//         }
//         s.erase(itr);
//         itr--;
//       }
//       if (itr < s.begin())
//         return s;
//       if (*itr == '*') {
//         s.erase(itr);
//         pop_amt++;
//       }
//       itr--;
//     }
//     return s;
//   }
// };

int main() {
  Solution sol;
  string s[] = {
      "leet**cod*e", "abc",    "a*bc",    "ab*c",
      "a*b*c",       "a*b*c*", "a*b*c**", "x*f*zt*a**t*i*rs*ggw*yb*j*y"};
  for (auto x : s) {
    cout << sol.removeStars(x) << endl;
  }
  return 0;
}
