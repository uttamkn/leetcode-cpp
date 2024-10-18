#include <bits/stdc++.h>
#include <numeric>
using namespace std;

class Solution {
public:
  bool canVisitAllRooms(vector<vector<int>> &rooms) {
    vector<int> visited(rooms.size(), 0);
    visited[0] = 1;
    stack<int> stk;
    stk.push(0);

    while (!stk.empty()) {
      int i = stk.top();
      stk.pop();

      for (int key : rooms[i]) {
        if (visited[key] == 0) {
          visited[key] = 1;
          stk.push(key);
        }
      }
    }

    return (rooms.size() == accumulate(visited.begin(), visited.end(), 0));
  }
};

int main() {
  Solution solution;
  return 0;
}
