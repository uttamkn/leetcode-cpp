#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string predictPartyVictory(string senate) {
    queue<char> turns;
    int i = 0, cancelled_Ds = 0, cancelled_Rs = 0, d = 0, r = 0;
    while (i < senate.size()) {
      (senate.at(i) == 'D') ? d++ : r++;
      turns.push(senate.at(i));
      i++;
    }

    while (d != 0 && r != 0) {
      if (turns.front() == 'D' && cancelled_Ds) {
        turns.pop();
        cancelled_Ds--;
        d--;
      } else if (turns.front() == 'R' && cancelled_Rs) {
        turns.pop();
        cancelled_Rs--;
        r--;
      } else {
        char cur_turn = turns.front();
        (cur_turn == 'D') ? cancelled_Rs++ : cancelled_Ds++;
        turns.pop();
        turns.push(cur_turn);
      }
    }

    return (d == 0) ? "Radiant" : "Dire";
  }
};

int main() {
  Solution sol;
  string senate[] = {"RD", "RDD", "DDRRR", "DRRDRDRDRDDRDRDR"};
  string expected[] = {"Radiant", "Dire", "Dire", "Radiant"};
  for (int i = 0; i < 4; i++) {
    if (sol.predictPartyVictory(senate[i]) == expected[i])
      cout << "Test case passed" << endl;
    else
      cout << "Test case failed" << endl;
  }
  return 0;
}
