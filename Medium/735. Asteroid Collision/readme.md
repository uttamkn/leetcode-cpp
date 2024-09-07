# 735. asteroid collision

we are given an array `asteroids` of integers representing asteroids in a row.

for each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). each asteroid moves at the same speed.

find out the state of the asteroids after all collisions. if two asteroids meet, the smaller one will explode. if both are the same size, both will explode. two asteroids moving in the same direction will never meet.

## example 1:

**input:** `asteroids = [5,10,-5]`

**output:** `[5,10]`

**explanation:** the 10 and -5 collide resulting in 10. the 5 and 10 never collide.

## example 2:

**input:** `asteroids = [8,-8]`

**output:** `[]`

**explanation:** the 8 and -8 collide exploding each other.

## example 3:

**input:** `asteroids = [10,2,-5]`

**output:** `[10]`

**explanation:** the 2 and -5 collide resulting in -5. the 10 and -5 collide resulting in 10.

## constraints:

- $2 \leq \text{asteroids.length} \leq 10^4$
- $-1000 \leq \text{asteroids}[i] \leq 1000$
- $\text{asteroids}[i] \neq 0$
