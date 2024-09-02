# 1207. Unique Number of Occurrences

## Problem Description

Given an array of integers `arr`, return `true` if the number of occurrences of each value in the array is unique or `false` otherwise.

## Examples

### Example 1

**Input:** `arr = [1,2,2,1,1,3]`  
**Output:** `true`  
**Explanation:**  
The value `1` has `3` occurrences, `2` has `2` occurrences, and `3` has `1` occurrence. No two values have the same number of occurrences.

### Example 2

**Input:** `arr = [1,2]`  
**Output:** `false`  
**Explanation:**  
The value `1` has `1` occurrence and `2` has `1` occurrence. The number of occurrences is not unique.

### Example 3

**Input:** `arr = [-3,0,1,-3,1,1,1,-3,10,0]`  
**Output:** `true`  
**Explanation:**  
The value `-3` has `3` occurrences, `0` has `2` occurrences, `1` has `4` occurrences, and `10` has `1` occurrence. All numbers of occurrences are unique.

## Constraints

- `1 <= arr.length <= 1000`
- `-1000 <= arr[i] <= 1000`
