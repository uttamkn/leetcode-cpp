# 1493. Longest Subarray of 1's After Deleting One Element

## Problem Description

Given a binary array `nums`, you should delete one element from it. Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return `0` if there is no such subarray.

## Examples

### Example 1:

**Input:** `nums = [1,1,0,1]`  
**Output:** `3`  
**Explanation:** After deleting the number at position 2, the array becomes `[1,1,1]` which contains 3 ones.

### Example 2:

**Input:** `nums = [0,1,1,1,0,1,1,0,1]`  
**Output:** `5`  
**Explanation:** After deleting the number at position 4, the array becomes `[0,1,1,1,1,1,0,1]`. The longest subarray with only ones is `[1,1,1,1,1]`.

### Example 3:

**Input:** `nums = [1,1,1]`  
**Output:** `2`  
**Explanation:** You must delete one element, so the longest subarray can only have 2 ones.

## Constraints

- `1 <= nums.length <= 10^5`
- `nums[i]` is either `0` or `1`.

## Solution Approach

To solve this problem, we can use a sliding window approach to track the longest subarray that contains at most one `0`. Since we are allowed to delete one element, we can treat this as a problem where we find the longest subarray with at most one `0`.

### Steps:

1. Initialize two pointers `left` and `right` at the start of the array and a variable `zero_count` to keep track of the number of zeros in the current window.
2. Move the `right` pointer to expand the window. If `nums[right]` is `0`, increment the `zero_count`.
3. If `zero_count` exceeds 1, move the `left` pointer to shrink the window until `zero_count` is 1 or less.
4. Track the maximum length of the window with only one zero and subtract one to account for the deletion.
5. Return the maximum length.

### Edge Case:

- If the array contains only ones, the result should be the length of the array minus one since one element must be deleted.

This approach runs in O(n) time, where `n` is the length of the array.
