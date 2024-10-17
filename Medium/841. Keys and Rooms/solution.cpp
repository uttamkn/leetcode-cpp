#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool canVisitAllRooms(vector<vector<int>> &rooms) {
    vector<int> visited(rooms.size(), 0);
    visited[0] = 1;

    for (vector<int> keys : rooms) {
      for (int key : keys) {
        if (visited[key] == 0)
          visited[key] = 1;
      }
    }
  }
};

int main() {
  Solution solution;
  return 0;
}
