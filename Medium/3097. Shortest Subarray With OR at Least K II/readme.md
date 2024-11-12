### 3097. Shortest Subarray With OR at Least K II

You are given an array `nums` of non-negative integers and an integer `k`.

An array is called **special** if the bitwise OR of all of its elements is **at least `k`**.

Return the length of the shortest special **non-empty subarray** of `nums`, or return `-1` if no special subarray exists.

#### Examples

**Example 1:**

```plaintext
Input: nums = [1,2,3], k = 2
Output: 1
Explanation: The subarray [3] has an OR value of 3, which is >= k. Hence, we return 1.
```

**Example 2:**

```plaintext
Input: nums = [2,1,8], k = 10
Output: 3
Explanation: The subarray [2,1,8] has an OR value of 11, which is >= k. Hence, we return 3.
```

**Example 3:**

```plaintext
Input: nums = [1,2], k = 0
Output: 1
Explanation: The subarray [1] has an OR value of 1, which is >= k. Hence, we return 1.
```

#### Constraints:

- \( 1 \leq \text{nums.length} \leq 2 \times 10^5 \)
- \( 0 \leq \text{nums}[i] \leq 10^9 \)
- \( 0 \leq k \leq 10^9 \)
