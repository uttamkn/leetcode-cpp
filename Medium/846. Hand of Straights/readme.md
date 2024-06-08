# 846. Hand of Straights

## Problem Description

Alice has some number of cards and she wants to rearrange the cards into groups so that each group is of size `groupSize`, and consists of `groupSize` consecutive cards.

Given an integer array `hand` where `hand[i]` is the value written on the `i`th card and an integer `groupSize`, return `true` if she can rearrange the cards, or `false` otherwise.

## Examples

### Example 1

Input: `hand = [1,2,3,6,2,3,4,7,8]`, `groupSize = 3`  
Output: `true`  
Explanation: Alice's hand can be rearranged as `[1,2,3],[2,3,4],[6,7,8]`

### Example 2

Input: `hand = [1,2,3,4,5]`, `groupSize = 4`  
Output: `false`  
Explanation: Alice's hand cannot be rearranged into groups of 4.

## Constraints

- `1 <= hand.length <= 10^4`
- `0 <= hand[i] <= 10^9`
- `1 <= groupSize <= hand.length`

**Note**: This question is the same as 1296.
