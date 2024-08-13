# 1732. Find the Highest Altitude

## Problem Description

A biker is going on a road trip that consists of `n + 1` points at different altitudes. The biker starts the trip at point `0` with an initial altitude of `0`.

You are given an integer array `gain` of length `n`, where `gain[i]` represents the net gain in altitude between points `i` and `i + 1`. Return the highest altitude reached during the trip.

## Examples

### Example 1:

**Input:** `gain = [-5, 1, 5, 0, -7]`  
**Output:** `1`  
**Explanation:** The altitudes at each point are `[0, -5, -4, 1, 1, -6]`. The highest altitude is `1`.

### Example 2:

**Input:** `gain = [-4, -3, -2, -1, 4, 3, 2]`  
**Output:** `0`  
**Explanation:** The altitudes at each point are `[0, -4, -7, -9, -10, -6, -3, -1]`. The highest altitude is `0`.

## Constraints

- `n == gain.length`
- `1 <= n <= 100`
- `-100 <= gain[i] <= 100`

## Solution Approach

### Steps:

1. **Initialization:**

   - Start with an initial altitude `current_altitude = 0`.
   - Initialize `max_altitude = 0` since the biker starts at altitude 0.

2. **Iterate through the `gain` array:**

   - For each `gain[i]`, calculate the new altitude by adding `gain[i]` to `current_altitude`.
   - Update `max_altitude` if the new altitude is higher than the current `max_altitude`.

3. **Return the `max_altitude`** after processing all the elements in the `gain` array.

### Example Walkthrough:

For `gain = [-5, 1, 5, 0, -7]`:

- Initial altitude: `0`
- After first gain: `0 - 5 = -5`
- After second gain: `-5 + 1 = -4`
- After third gain: `-4 + 5 = 1`
- After fourth gain: `1 + 0 = 1`
- After fifth gain: `1 - 7 = -6`

The highest altitude is `1`.

### Complexity:

- **Time Complexity:** O(n), where `n` is the length of the `gain` array.
- **Space Complexity:** O(1), only a few extra variables are used.

This approach ensures that we efficiently find the highest altitude during the biker's journey.
