## 994. rotting oranges

you are given an $m \times n$ grid where each cell can have one of three values:

- 0 representing an empty cell,
- 1 representing a fresh orange, or
- 2 representing a rotten orange.

every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

return the minimum number of minutes that must elapse until no cell has a fresh orange. if this is impossible, return -1.

### example 1:

- **input**: `grid = [[2,1,1],[1,1,0],[0,1,1]]`
- **output**: `4`

### example 2:

- **input**: `grid = [[2,1,1],[0,1,1],[1,0,1]]`
- **output**: `-1`  
  **explanation**: the orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.

### example 3:

- **input**: `grid = [[0,2]]`
- **output**: `0`  
  **explanation**: since there are already no fresh oranges at minute 0, the answer is just 0.

### constraints:

- $m = \text{grid.length}$
- $n = \text{grid}[i].\text{length}$
- $1 \leq m, n \leq 10$
- $\text{grid}[i][j]$ is 0, 1, or 2.
