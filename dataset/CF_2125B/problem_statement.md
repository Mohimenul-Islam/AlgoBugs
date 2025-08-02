# B. Left and Down

**Time limit:** 2 seconds
**Memory limit:** 512 megabytes
**Input:** standard input
**Output:** standard output

## Problem Statement

There is a robot located in the cell $$$(a,b)$$$ of an infinite grid. Misha wants to move it to the cell $$$(0,0)$$$. To do this, he has fixed some integer $$$k$$$.Misha can perform the following operation: choose two integers $$$dx$$$ and $$$dy$$$ (both from $$$0$$$ to $$$k$$$ inclusive) and move the robot $$$dx$$$ cells to the left (in the direction of decreasing $$$x$$$ coordinate) and $$$dy$$$ cells down (in the direction of decreasing $$$y$$$ coordinate). In other words, move the robot from $$$(x,y)$$$ to $$$(x - dx, y - dy)$$$.The cost of the operation is:   $$$1$$$, if the chosen pair $$$(dx,dy)$$$ is used for the first time;  $$$0$$$, if the pair $$$(dx,dy)$$$ has been chosen before. Note that if $$$dx \ne dy$$$, the pairs $$$(dx, dy)$$$ and $$$(dy, dx)$$$ are considered different.Help Misha bring the robot to the cell $$$(0,0)$$$ with minimum total cost. Note that you don't have to minimize the number of operations.

## Input

The first line contains a single integer $$$t$$$ ($$$1 \le t \le 10^4$$$) — the number of test cases.The only line of each test case contains three integers $$$a, b$$$, and $$$k$$$ ($$$1 \le a, b, k \le 10^{18}$$$).

## Output

For each test case, output a single integer — the minimum total cost of operations required to move the robot to the cell $$$(0,0)$$$.

## Example

### Input
```
43 5 152 3 112 18 89 7 5
```

### Output
```
1
2
1
2
```

## Note

In the first test case, the operation $$$(3,5)$$$ can be applied once. The robot will immediately go to $$$(0,0)$$$, and the cost of the operation will be $$$1$$$.In the second test case, the operations: $$$(1,1)$$$, $$$(0,1)$$$, and $$$(1,1)$$$ can be applied. After the first operation, the robot will be at cell $$$(1,2)$$$, after the second one — at $$$(1,1)$$$, and after the third one — at $$$(0,0)$$$. The cost of the first and second operations is $$$1$$$, while the third is $$$0$$$, as the pair $$$(1,1)$$$ has already been used in the first operation.In the third test case, the pair $$$(4,6)$$$ can be chosen three times in a row.In the fourth test case, the operations: $$$(4,2)$$$ and $$$(5,5)$$$ can be applied.