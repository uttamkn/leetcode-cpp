#include "../macros.h"
using namespace std;

class Solution {
public:
  bool isvalid(string s) {
    stack<char> stk;
    for (const char c : s) {
      if (c == '[' || c == '(' || c == '{')
        stk.push(c);
      else {
        if (stk.empty())
          return false;

        switch (c) {
        case '}': {
          if (stk.top() == '{')
            stk.pop();
          else
            return false;
        } break;

        case ')': {
          if (stk.top() == '(')
            stk.pop();
          else
            return false;
        } break;

        case ']': {
          if (stk.top() == '[')
            stk.pop();
          else
            return false;
        } break;
        }
      }
    }

    return stk.empty();
  }
};

int main() {
  Solution solution;
  return 0;
}
