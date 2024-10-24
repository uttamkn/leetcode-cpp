#include <bits/stdc++.h>
using namespace std;

class Solution {

public:
  int minReorder(int n, vector<vector<int>> &connections) {
    unordered_map<int, vector<int>> adj;
    vector<int> visited(n);
    int res = 0;

    for (vector<int> connection : connections) {
      adj[connection[1]].push_back(connection[0]);
      adj[connection[0]].push_back(-connection[1]);
    }

    dfs(0, visited, adj, res);

    return res;
  }

private:
  void dfs(int node, vector<int> &visited, unordered_map<int, vector<int>> &adj,
           int &cost) {

    visited[node] = 1;
    for (int &i : adj[node]) {
      if (!visited[abs(i)]) {
        if (i >= 0) {
          dfs(i, visited, adj, cost);
        } else {
          cost++;
          i *= -1;
          dfs(i, visited, adj, cost);
        }
      }
    }
  }
};

int main() {
  Solution solution;
  vector<vector<int>> a = {{0, 1}, {1, 3}, {2, 3}, {4, 0}, {4, 5}};
  vector<vector<int>> b = {{1, 2}, {2, 0}};

  cout << "a: " << solution.minReorder(6, a) << endl; // 3
  cout << "b: " << solution.minReorder(3, b) << endl; // 0
  return 0;
}
