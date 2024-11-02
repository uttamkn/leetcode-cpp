## 17. letter combinations of a phone number

given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. return the answer in any order.

a mapping of digits to letters (just like on the telephone buttons) is given below. note that 1 does not map to any letters.

### example 1:

**input:** `digits = "23"`  
**output:** `["ad","ae","af","bd","be","bf","cd","ce","cf"]`

### example 2:

**input:** `digits = ""`  
**output:** `[]`

### example 3:

**input:** `digits = "2"`  
**output:** `["a","b","c"]`

### constraints:

- $0 \leq \text{digits.length} \leq 4$
- $\text{digits}[i]$ is a digit in the range `['2', '9']`.
