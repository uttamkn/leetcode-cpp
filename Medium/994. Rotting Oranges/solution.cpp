#include <bits/stdc++.h>

class Solution {
public:
  int orangesRotting(std::vector<std::vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    int numOfRotten = 0;
    int numOfOranges = 0;

    std::queue<std::pair<int, int>> q;

    std::vector<int> moveRows = {-1, 1, 0, 0};
    std::vector<int> moveCols = {0, 0, -1, 1};

    int mins = 0;

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 2) {
          q.push({i, j});
          numOfRotten++;
          numOfOranges++;
          continue;
        }
        if (grid[i][j] == 1) {
          numOfOranges++;
        }
      }
    }

    while (!q.empty()) {
      int size = q.size();
      bool didRot = false;
      printGrid(grid);
      for (int i = 0; i < size; ++i) {
        auto [row, col] = q.front();
        q.pop();

        for (int j = 0; j < 4; ++j) {
          int newRow = row + moveRows[j];
          int newCol = col + moveCols[j];

          if (newRow >= 0 && newCol >= 0 && newRow < m && newCol < n &&
              grid[newRow][newCol] == 1) {
            didRot = true;
            grid[newRow][newCol] = 2;
            q.push({newRow, newCol});
            numOfRotten++;
          }
        }
      }
      if (didRot)
        mins++;
    }

    return (numOfRotten != numOfOranges) ? -1 : mins;
  }

  void printGrid(std::vector<std::vector<int>> &grid) {
    for (auto &row : grid) {
      for (int &cell : row) {
        std::cout << cell << " ";
      }
      std::cout << std::endl;
    }
  }
};

int main() {
  Solution solution;
  std::vector<std::vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
  std::cout << solution.orangesRotting(grid) << std::endl;
  return 0;
}
