# 215. Kth Largest Element in an Array

Given an integer array `nums` and an integer `k`, return the _kth_ largest element in the array.

Note that it is the _kth_ largest element in the sorted order, not the _kth_ distinct element.

Can you solve it without sorting?

---

### Example 1:

**Input:**

```plaintext
nums = [3,2,1,5,6,4], k = 2
```

**Output:**

```plaintext
5
```

### Example 2:

**Input:**

```plaintext
nums = [3,2,3,1,2,4,5,5,6], k = 4
```

**Output:**

```plaintext
4
```

---

### Constraints:

- $1 \leq k \leq \text{nums.length} \leq 10^5$
- $-10^4 \leq \text{nums}[i] \leq 10^4$
