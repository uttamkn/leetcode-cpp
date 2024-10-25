### 399. evaluate division

you are given an array of variable pairs `equations` and an array of real numbers `values`, where `equations[i] = [Ai, Bi]` and `values[i]` represent the equation $A_i / B_i = \text{values}[i]$. each `Ai` or `Bi` is a string that represents a single variable.

you are also given some `queries`, where `queries[j] = [Cj, Dj]` represents the $j^{\text{th}}$ query where you must find the answer for $C_j / D_j = \ ?$.

return the answers to all queries. if a single answer cannot be determined, return `-1.0`.

**note**: the input is always valid. you may assume that evaluating the queries will not result in division by zero and that there is no contradiction.

**note**: the variables that do not occur in the list of equations are undefined, so the answer cannot be determined for them.

---

#### example 1:

**input**:  
`equations = [["a","b"],["b","c"]]`,  
`values = [2.0,3.0]`,  
`queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]`

**output**:  
`[6.00000, 0.50000, -1.00000, 1.00000, -1.00000]`

**explanation**:  
given: $a / b = 2.0$, $b / c = 3.0$  
queries are: $a / c = \ ?$, $b / a = \ ?$, $a / e = \ ?$, $a / a = \ ?$, $x / x = \ ?$  
return: `[6.0, 0.5, -1.0, 1.0, -1.0]`  
note: $x$ is undefined $\Rightarrow -1.0$

---

#### example 2:

**input**:  
`equations = [["a","b"],["b","c"],["bc","cd"]]`,  
`values = [1.5,2.5,5.0]`,  
`queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]`

**output**:  
`[3.75000, 0.40000, 5.00000, 0.20000]`

---

#### example 3:

**input**:  
`equations = [["a","b"]]`,  
`values = [0.5]`,  
`queries = [["a","b"],["b","a"],["a","c"],["x","y"]]`

**output**:  
`[0.50000, 2.00000, -1.00000, -1.00000]`

---

#### constraints:

- $1 \leq \text{equations.length} \leq 20$
- $\text{equations}[i].\text{length} == 2$
- $1 \leq |A_i|, |B_i| \leq 5$
- $\text{values.length} == \text{equations.length}$
- $0.0 < \text{values}[i] \leq 20.0$
- $1 \leq \text{queries.length} \leq 20$
- $\text{queries}[i].\text{length} == 2$
- $1 \leq |C_j|, |D_j| \leq 5$
- $A_i, B_i, C_j, D_j$ consist of lowercase english letters and digits.
