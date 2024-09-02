#include <bits/stdc++.h>
using namespace std;

struct VectorHash {
  std::size_t operator()(const std::vector<int> &v) const {
    std::size_t hash = v.size();
    for (int a : v) {
      hash ^= std::hash<int>{}(a) + 0x9e3779b9 + (hash << 6) + (hash >> 2);
    }
    return hash;
  }
};

class Solution {
public:
  int equalPairs(vector<vector<int>> &grid) {
    unordered_map<vector<int>, int, VectorHash> rows, cols;
    int n = grid.size();
    int ans = 0;

    for (int i = 0; i < n; ++i) {
      rows[grid[i]]++;
      vector<int> temp(n);
      for (int j = 0; j < n; ++j) {
        temp[j] = grid[j][i];
      }
      cols[temp]++;
    }

    for (auto it = rows.begin(); it != rows.end(); ++it) {
      auto col = cols.find(it->first);
      if (col != cols.end()) {
        ans += it->second * col->second;
      }
    }

    return ans;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> tests[] = {
      {{3, 2, 1}, {1, 7, 6}, {2, 7, 7}},
      {{3, 1, 2, 2}, {1, 4, 4, 5}, {2, 4, 2, 2}, {2, 4, 2, 2}},
      {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}},
  };
  for (auto &test : tests) {
    cout << sol.equalPairs(test) << endl;
  }
  return 0;
}
