#include <algorithm>
#include <bits/stdc++.h>

class Solution {
public:
  int nearestExit(std::vector<std::vector<char>> &maze,
                  std::vector<int> &entrance) {

    int rows = maze.size();
    int cols = maze[0].size();

    int shortestPath = INT_MAX;

    std::vector<std::vector<bool>> visited(rows,
                                           std::vector<bool>(cols, false));
    std::queue<std::pair<std::pair<int, int>, int>> q;
    std::vector yAxis = {-1, 1, 0, 0};
    std::vector xAxis = {0, 0, -1, 1};

    q.push({{entrance[0], entrance[1]}, 0});
    visited[entrance[0]][entrance[1]] = true;

    while (!q.empty()) {
      auto [pos, dist] = q.front();
      int row = pos.first;
      int col = pos.second;
      q.pop();

      for (int i = 0; i < 4; ++i) {
        int newRow = row + yAxis[i];
        int newCol = col + xAxis[i];

        bool isOutsideMaze =
            (newCol < 0 || newRow < 0 || newCol >= cols || newRow >= rows);
        bool isAtEntrance = row == entrance[0] && col == entrance[1];

        if (isOutsideMaze && !isAtEntrance) {
          shortestPath = std::min(shortestPath, dist);
        } else if (!isOutsideMaze && !visited[newRow][newCol] &&
                   maze[newRow][newCol] == '.') {
          visited[newRow][newCol] = true;
          q.push({{newRow, newCol}, dist + 1});
        }
      }
    }

    return (shortestPath == INT_MAX) ? -1 : shortestPath;
  }
};

int main() {
  Solution solution;
  return 0;
}
