# 2864. Maximum Odd Binary Number

## Problem Statement

You are given a binary string `s` that contains at least one '1'.

You have to rearrange the bits in such a way that the resulting binary number is the maximum odd binary number that can be created from this combination.

Return a string representing the maximum odd binary number that can be created from the given combination.

Note that the resulting string can have leading zeros.

## Examples

### Example 1

Input: `s = "010"`

Output: `"001"`

Explanation: Because there is just one '1', it must be in the last position. So the answer is "001".

### Example 2

Input: `s = "0101"`

Output: `"1001"`

Explanation: One of the '1's must be in the last position. The maximum number that can be made with the remaining digits is "100". So the answer is "1001".

## Constraints

- 1 <= s.length <= 100
- `s` consists only of '0' and '1'.
- `s` contains at least one '1'.

## Intuition

The goal of this code is to create the maximum odd binary number from the given string s. It counts the number of '1's in the input string and then constructs the output string accordingly.

## Approach

- Count the number of '1's in the input string s.
- Iterate through the input string, appending '1' to the result until there is only one '1' left.
- Append '0' when there is only one '1' left to ensure the result is an odd binary number.
- Finally, append the last '1' to the result.

## Complexity

- Time complexity: O(n), where n is the length of the input string s. The code iterates through the string once.

- Space complexity: O(1), as the space used is constant regardless of the input size. The variables used are num_of_ones, res, and i.
