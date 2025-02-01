#include "../macros.h"
using namespace std;

class Solution {
public:
  bool isValidSudoku(vector<vector<char>> &board) {
    uset<char> row, col;
    int grid_size = 9;

    rep(i, 0, grid_size) {
      rep(j, 0, grid_size) {
        // row
        if (board[i][j] != '.') {
          if (row.count(board[i][j])) {
            return false;
          }
          row.insert(board[i][j]);
        }

        // col
        if (board[j][i] != '.') {
          if (col.count(board[j][i])) {
            return false;
          }
          col.insert(board[j][i]);
        }
      }
      row.clear();
      col.clear();
    }

    for (int i = 0; i < 9; i += 3) {
      for (int j = 0; j < 9; j += 3) {
        if (isInvalidGrid(board, {i, j})) {
          return false;
        }
      }
    }

    return true;
  }

  bool isInvalidGrid(vector<vector<char>> &board, pair<int, int> cords) {
    const auto [x, y] = cords;
    uset<char> block;

    rep(i, x, x + 3) {
      rep(j, y, y + 3) {
        if (board[i][j] != '.') {
          if (block.count(board[i][j])) {
            return true;
          }
          block.insert(board[i][j]);
        }
      }
    }

    return false;
  }
};

int main() {
  Solution solution;
  vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                {'6', '.', '3', '1', '9', '5', '.', '.', '.'},
                                {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

  cout << solution.isValidSudoku(board) << endl;
  return 0;
}
