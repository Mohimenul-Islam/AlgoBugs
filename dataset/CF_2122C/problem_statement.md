# C. Manhattan Pairs

**Time limit:** 2 seconds
**Memory limit:** 256 megabytes
**Input:** standard input
**Output:** standard output

## Problem Statement

You are given $$$n$$$ points $$$(x_i, y_i)$$$ on a 2D plane, where $$$n$$$ is even. Select $$$\tfrac{n}{2}$$$ disjoint pairs $$$(a_i, b_i)$$$ to maximize the sum of Manhattan distances between points in pairs. In other words, maximize $$$$$$\sum_{i=1}^{n/2} |x_{a_i} - x_{b_i}| + |y_{a_i} - y_{b_i}|.$$$$$$

## Input

Each test contains multiple test cases. The first line contains the number of test cases $$$t$$$ ($$$1 \le t \le 10^4$$$). The description of the test cases follows. The first line of each test case contains a single even integer $$$n$$$ ($$$2 \leq n \leq 2 \cdot 10^5$$$) — the number of points.The $$$i$$$-th of the next $$$n$$$ lines contains two integers $$$x_i$$$ and $$$y_i$$$ ($$$-10^6 \le x_i, y_i \le 10^6$$$) — the coordinates of the $$$i$$$-th point.It is guaranteed that the sum of $$$n$$$ over all test cases does not exceed $$$2 \cdot 10^5$$$.

## Output

For each test case, output $$$\tfrac{n}{2}$$$ lines, the $$$i$$$-th line containing two integers $$$a_i$$$ and $$$b_i$$$ — the indices of points in the $$$i$$$-th pair.If there are multiple solutions, print any of them.

## Example

### Input
```
241 13 04 23 410-1 -1-1 2-2 -2-2 00 22 -3-4 -4-4 -20 1-4 -2
```

### Output
```
4 1
2 3
8 1
9 10
7 5
2 3
6 4
```

## Note

In the first test case, an optimal solution is to select the pairs $$$(1, 4)$$$ and $$$(2, 3)$$$, which achieves a distance sum of $$$5 + 3 = 8$$$.In the second test case, an optimal solution is to select the pairs $$$(1, 8)$$$, $$$(9, 10)$$$, $$$(5, 7)$$$, $$$(2, 3)$$$, $$$(4, 6)$$$, which achieves a distance sum of $$$4 + 7 + 10 + 5 + 7 = 33$$$.