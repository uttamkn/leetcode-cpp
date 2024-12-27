#include "../../macros.h"

class Solution {
public:
  vector<string> generateParenthesis(int n) {
    vector<string> res;
    f(2 * n, res, "");
    return res;
  }

  bool is_valid(const string combination) {
    int open = 0, close = 0;

    for (const char c : combination) {
      if (c == '(')
        open++;
      else
        close++;

      if (close > open)
        return false;
    }

    return open == close;
  }

private:
  void f(int size, vector<string> &res, string cur_combination) {
    if (size == 0) {
      if (is_valid(cur_combination))
        res.push_back(cur_combination);
      return;
    }

    f(size-1, res, cur_combination + "(");
    if (sz(cur_combination) != 0)
      f(size-1, res, cur_combination + ")");
  }
};

int main() {
  Solution s;
  // bool test = s.is_valid("((((");
  // dbg(test)
  dbg_vec(s.generateParenthesis(3));
}
