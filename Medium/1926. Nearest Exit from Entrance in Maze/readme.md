## 1926. nearest exit from entrance in maze

you are given an $m \times n$ matrix `maze` (0-indexed) with empty cells (represented as `.`) and walls (represented as `+`). you are also given the entrance of the maze, where `entrance = [\text{entrancerow}, \text{entrancecol}]` denotes the row and column of the cell you are initially standing at.

in one step, you can move one cell up, down, left, or right. you cannot step into a cell with a wall, and you cannot step outside the maze. your goal is to find the nearest exit from the entrance. an exit is defined as an empty cell that is at the border of the maze. the entrance does not count as an exit.

return the number of steps in the shortest path from the entrance to the nearest exit, or `-1` if no such path exists.

### example 1:

**input:** `maze = [["+", "+", ".", "+"], [".", ".", ".", "+"], ["+", "+", "+", "."]]`, `entrance = [1, 2]`  
**output:** `1`  
**explanation:** there are 3 exits in this maze at `[1,0]`, `[0,2]`, and `[2,3]`.  
initially, you are at the entrance cell `[1,2]`.

- you can reach `[1,0]` by moving 2 steps left.
- you can reach `[0,2]` by moving 1 step up.

it is impossible to reach `[2,3]` from the entrance. thus, the nearest exit is `[0,2]`, which is 1 step away.

### example 2:

**input:** `maze = [["+", "+", "+"], [".", ".", "."], ["+", "+", "+"]]`, `entrance = [1,0]`  
**output:** `2`  
**explanation:** there is 1 exit in this maze at `[1,2]`.  
`[1,0]` does not count as an exit since it is the entrance cell. initially, you are at the entrance cell `[1,0]`.

- you can reach `[1,2]` by moving 2 steps right.

thus, the nearest exit is `[1,2]`, which is 2 steps away.

### example 3:

**input:** `maze = [[".", "+"]]`, `entrance = [0,0]`  
**output:** `-1`  
**explanation:** there are no exits in this maze.

### constraints:

- `maze.length == m`
- `maze[i].length == n`
- $1 \leq m, n \leq 100$
- `maze[i][j]` is either `.` or `+`.
- `entrance.length == 2`
- $0 \leq \text{entrancerow} < m$
- $0 \leq \text{entrancecol} < n$
- entrance will always be an empty cell.
