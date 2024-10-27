#include <bits/stdc++.h>

class Solution {
public:
  int orangesRotting(std::vector<std::vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();

    std::vector<std::vector<bool>> visited(m, std::vector<bool>(n, false));
    std::queue<std::pair<int, int>> q;

    std::vector<int> moveRows = {-1, 1, 0, 0};
    std::vector<int> moveCols = {0, 0, -1, 1};

    int mins = 0;

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < m; ++j) {
        if (grid[i][j] == 2) {
          q.push({i, j});
          visited[i][j] = true;
        }
      }
    }

    while (!q.empty()) {

      auto [row, col] = q.front();
      q.pop();

      for (int j = 0; j < 4; ++j) {
        int newRow = row + moveRows[j];
        int newCol = row + moveCols[j];

        if (newRow >= 0 && newCol >= 0 && newRow < m && newCol < n &&
            !visited[newRow][newCol] && grid[newRow][newCol] == 1) {
          visited[newRow][newCol] = true;
          q.push({newRow, newCol});
        }
      }
      mins++;
    }
    return mins;
  }
};

int main() {
  Solution solution;
  return 0;
}
