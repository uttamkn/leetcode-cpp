#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int numTimesAllBlue(vector<int> &flips) {
    int curMax = 0, curSize = 0, res = 0;
    for (int flip : flips) {
      curSize++;
      if (flip > curMax)
        curMax = flip;
      if (curMax == curSize)
        res++;
    }
    return res;
  }
};

int main() {
  Solution solution;
  return 0;
}
