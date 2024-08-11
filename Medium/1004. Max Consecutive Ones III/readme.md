# 1004. Max Consecutive Ones III

## Problem Description

Given a binary array `nums` and an integer `k`, return the maximum number of consecutive 1's in the array if you can flip at most `k` 0's.

## Examples

### Example 1:

**Input:** `nums = [1,1,1,0,0,0,1,1,1,1,0]`, `k = 2`  
**Output:** `6`  
**Explanation:** After flipping two 0's, the array becomes `[1,1,1,0,0,1,1,1,1,1,1]`. The longest subarray is underlined.

### Example 2:

**Input:** `nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1]`, `k = 3`  
**Output:** `10`  
**Explanation:** After flipping three 0's, the array becomes `[0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]`. The longest subarray is underlined.

## Constraints

- `1 <= nums.length <= 10^5`
- `nums[i]` is either `0` or `1`.
- `0 <= k <= nums.length`

## Solution Approach

To solve this problem, we can use the sliding window technique. The main idea is to maintain a window that contains at most `k` zeros. We will expand the window by moving the right pointer until the condition is violated, then shrink the window by moving the left pointer until the condition is satisfied again.

### Steps:

1. Initialize two pointers `left` and `right` at the start of the array and a variable `zero_count` to keep track of the number of zeros in the current window.
2. Move the `right` pointer to expand the window. If `nums[right]` is `0`, increment the `zero_count`.
3. If `zero_count` exceeds `k`, move the `left` pointer to shrink the window until `zero_count` is less than or equal to `k`.
4. Track the maximum length of the window during this process.
5. Return the maximum length.

This approach works in O(n) time, where `n` is the length of the array.
