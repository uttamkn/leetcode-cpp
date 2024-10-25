#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int findCircleNum(vector<vector<int>> &isConnected) {
    vector<int> visited(isConnected.size(), 0);
    int numOfProvinces = 1;

    dfs(0, visited, isConnected);

    for (int i = 0; i < visited.size(); ++i) {
      if (visited[i] == 0) {
        numOfProvinces++;
        dfs(i, visited, isConnected);
      }
    }
    return numOfProvinces;
  }

private:
  void dfs(int node, vector<int> &visited, vector<vector<int>> &isConnected) {
    visited[node] = 1;
    for (int i = 0; i < isConnected[node].size(); ++i) {
      if (!visited[i] && isConnected[node][i]) {
        dfs(i, visited, isConnected);
      }
    }
  }
};

int main() {
  Solution solution;
  std::vector<std::vector<int>> isConnected = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
  std::cout << solution.findCircleNum(isConnected) << std::endl;
  return 0;
}
