# Problem Statement

A frog is on the **1st stair** of an **N-stair** long staircase and wants to reach the **Nth stair**.  
The height of the `(i+1)th` stair is given by the array `HEIGHT[i]`.

If the frog jumps from the `ith` stair to the `jth` stair, the energy lost in the jump is calculated as:

\[
\text{Energy Lost} = |HEIGHT[i-1] - HEIGHT[j-1]|
\]

If the frog is on the `ith` stair, it can jump either to the:

1. `(i+1)th` stair
2. `(i+2)th` stair

Your task is to find the **minimum total energy** used by the frog to reach from the **1st stair** to the **Nth stair**.

---

## Example

### Input

If the given `HEIGHT` array is `[10, 20, 30, 10]`:

- The answer is `20`.

**Explanation**:

- The frog can jump from the 1st stair to the 2nd stair (`|20-10| = 10` energy lost).
- Then jump from the 2nd stair to the 4th stair (`|10-20| = 10` energy lost).
- Total energy lost: `10 + 10 = 20`.

---

## Input/Output Format

### Input

- **T**: Number of test cases. (1 ≤ T ≤ 10)
- For each test case:
  - **N**: Number of stairs. (1 ≤ N ≤ 100,000)
  - **HEIGHT**: An array of heights of length **N**. (1 ≤ HEIGHT[i] ≤ 1000)

### Output

- For each test case, output the **minimum total energy** the frog uses to reach the last stair.

---

## Constraints

- 1 ≤ T ≤ 10
- 1 ≤ N ≤ 100,000
- 1 ≤ HEIGHT[i] ≤ 1000
- Time limit: **1 second**

---

## Sample Input 1

```
2
4
10 20 30 10
3
10 50 10
```

### Sample Output 1

```
20
0
```

### Explanation

#### Test Case 1:

- The frog can jump from the 1st stair to the 2nd stair (`|20-10| = 10` energy lost).
- Then jump from the 2nd stair to the 4th stair (`|10-20| = 10` energy lost).
- Total energy lost: `10 + 10 = 20`.

#### Test Case 2:

- The frog can jump directly from the 1st stair to the 3rd stair (`|10-10| = 0` energy lost).
- Total energy lost: `0`.

---

## Sample Input 2

```
2
8
7 4 4 2 6 6 3 4
6
4 8 3 10 4 4
```

### Sample Output 2

```
7
2
```

---

## Hints

1. **Explore possibilities** at each stair (e.g., jumping to the next or skipping one stair).
2. Use **recursion** to divide the problem into subproblems and calculate the answer for each subproblem only once (memoization or dynamic programming).
3. Alternatively, solve it **iteratively** using a bottom-up approach.
