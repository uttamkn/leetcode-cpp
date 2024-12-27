#include "../../macros.h"

class Solution {
public:
  vector<string> generateParenthesis(int n) {
    vector<string> res;
    f(n, res, "", 0, 0);
    return res;
  }

  // bool is_valid(const string combination) {
  //   int open = 0, close = 0;
  //
  //   for (const char c : combination) {
  //     if (c == '(')
  //       open++;
  //     else
  //       close++;
  //
  //     if (close > open)
  //       return false;
  //   }
  //
  //   return open == close;
  // }

private:
  void f(int size, vector<string> &res, string cur_combination, int open, int close) {
    if (open == close && open == size) {
      res.push_back(cur_combination);
      return;
    }

    if(open<size) {
      f(size, res, cur_combination+"(", open+1, close);
    }

    if(close < open) {
      f(size, res, cur_combination+")", open, close+1);
    }
  }
};

int main() {
  Solution s;
  // bool test = s.is_valid("((((");
  // dbg(test)
  dbg_vec(s.generateParenthesis(3));
}
