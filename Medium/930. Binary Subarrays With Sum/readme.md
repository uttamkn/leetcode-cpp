# 930. Binary Subarrays With Sum

## Problem Description

Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

A subarray is a contiguous part of the array.

## Examples

### Example 1

Input:

- nums = [1,0,1,0,1]
- goal = 2

Output:
4

Explanation:
The 4 subarrays are bolded and underlined below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]

### Example 2

Input:

- nums = [0,0,0,0,0]
- goal = 0

Output:
15

## Constraints

- 1 <= nums.length <= 3 * 10^4
- nums[i] is either 0 or 1.
- 0 <= goal <= nums.length

## For questions like these (finding the number of subarray with exact < something >)

- number of subarrays with exact < something > = number of subarrays with atmost < something > - number of subarrays with atmost < something - 1 >
- in this case find the difference between subarrays with atmost sum `goal` - subarrays with atmost sum `goal-1`
- similar to question 992
