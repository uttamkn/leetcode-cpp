# Ninjas Training Problem

Ninja is planning a ‘N’-day-long training schedule. Each day, he can perform any one of these three activities: **Running**, **Fighting Practice**, or **Learning New Moves**. Each activity has some merit points assigned to it for each day. To improve all his skills, Ninja **cannot perform the same activity on two consecutive days**.  

Your task is to help Ninja find the **maximum merit points** he can earn over the training schedule.

---

## Problem Statement
You are given a 2D array of size `N x 3` called `POINTS` where each row represents a day, and the three columns represent the merit points for the activities:  
1. **Column 1**: Running  
2. **Column 2**: Fighting Practice  
3. **Column 3**: Learning New Moves  

Your goal is to calculate the **maximum merit points Ninja can earn** by choosing one activity per day, ensuring no activity is repeated on consecutive days.

---

## Constraints:
- \( 1 \leq T \leq 10 \) (Number of test cases)  
- \( 1 \leq N \leq 100,000 \) (Number of days in the schedule)  
- \( 1 \leq \text{Values of POINTS array} \leq 100 \)  
- **Time Limit:** 1 second  

---

## Input Format:
1. First line contains an integer \( T \), the number of test cases.  
2. For each test case:  
   - First line contains \( N \), the number of days.  
   - Next \( N \) lines contain 3 integers each, representing merit points for Running, Fighting Practice, and Learning New Moves for that day.

---

## Output Format:
For each test case, output the maximum merit points Ninja can earn on a new line.

---

## Sample Input 1:
```
2
3
1 2 5 
3 1 1
3 3 3
3
10 40 70
20 50 80
30 60 90
```

## Sample Output 1:
```
11
210
```

---

## Explanation:

### Test Case 1:
The `POINTS` array is:
```
1 2 5
3 1 1
3 3 3
```
- **Day 1**: Ninja learns new moves (5 points).  
- **Day 2**: Ninja does running (3 points).  
- **Day 3**: Ninja does fighting practice (3 points).  
**Total merit points = 5 + 3 + 3 = 11** (maximum).

### Test Case 2:
The `POINTS` array is:
```
10 40 70
20 50 80
30 60 90
```
- **Day 1**: Ninja learns new moves (70 points).  
- **Day 2**: Ninja does fighting practice (50 points).  
- **Day 3**: Ninja learns new moves again (90 points).  
**Total merit points = 70 + 50 + 90 = 210** (maximum).

---

## Sample Input 2:
```
2
3
18 11 19
4 13 7
1 8 13
2
10 50 1
5 100 11
```

## Sample Output 2:
```
45
110
```

---

## Explanation:

### Test Case 1:
The `POINTS` array is:
```
18 11 19
4 13 7
1 8 13
```
- **Day 1**: Ninja learns new moves (19 points).  
- **Day 2**: Ninja does fighting practice (13 points).  
- **Day 3**: Ninja learns new moves again (13 points).  
**Total merit points = 19 + 13 + 13 = 45** (maximum).

### Test Case 2:
The `POINTS` array is:
```
10 50 1
5 100 11
```
- **Day 1**: Ninja does running practice (10 points).  
- **Day 2**: Ninja does fighting practice again (100 points).  
**Total merit points = 10 + 100 = 110** (maximum).

---

## Notes:
- The problem can be solved using **Dynamic Programming (DP)** to efficiently compute the maximum merit points while adhering to the constraints.  
