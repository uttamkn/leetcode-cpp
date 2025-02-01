#include <cctype>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  bool isPalindrome(string s) {
    int n = s.size(), i = 0, j = n - 1;

    while (i < j) {
      bool is_i_alnum = isalnum(s[i]);
      bool is_j_alnum = isalnum(s[j]);

      if (!is_i_alnum || !is_j_alnum) {
        if (!is_i_alnum)
          i++;
        if (!is_j_alnum)
          j--;

        continue;
      }

      if (tolower(s[i]) != tolower(s[j]))
        return false;

      i++;
      j--;
    }

    return true;
  }
};

int main() {
  Solution solution;
  string s = "was it a car or a cat i saw?";
  bool result = solution.isPalindrome(s);
  cout << result << endl;
  return 0;
}
