#include "../macros.h"
#include <vector>
using namespace std;

class Solution {
public:
  vector<string> generateParenthesis(int n) {
    vector<string> res;

    f(n, res, 0, 0, "");

    return res;
  }

private:
  void f(int n, vector<string> &res, int open, int close,
         string cur_combination) {
    if (cur_combination.size() == 2 * n) {
      res.push_back(cur_combination);
      return;
    }

    if (open < n) {
      f(n, res, open + 1, close, cur_combination + '(');
    }

    if (close < open && close < n)
      f(n, res, open, close + 1, cur_combination + ')');
  }
};

int main() {
  Solution solution;
  return 0;
}
