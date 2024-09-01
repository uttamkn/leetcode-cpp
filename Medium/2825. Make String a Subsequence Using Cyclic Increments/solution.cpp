#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool canMakeSubsequence(string str1, string str2) {
    int n1 = str1.size(), n2 = str2.size();
    if (n2 > n1)
      return false;

    int i = 0, j = 0;
    while (i < n1 && j < n2) {
      if (str1[i] == str2[j] || rot1(str1[i]) == str2[j]) {
        i++;
        j++;
      } else {
        i++;
      }
    }

    if (j == n2)
      return true;

    return false;
  }

private:
  char rot1(char ch) {
    if (ch == 'z')
      return 'a';
    else
      return char(int(ch) + 1);
  }
};

int main() {
  Solution sol;
  return 0;
}
