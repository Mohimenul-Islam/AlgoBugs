# D. 1709

**Time limit:** 2 seconds
**Memory limit:** 256 megabytes
**Input:** standard input
**Output:** standard output

## Problem Statement

You are given two arrays of integers $$$a_1, a_2, \ldots, a_n$$$ and $$$b_1, b_2, \ldots, b_n$$$. It is guaranteed that each integer from $$$1$$$ to $$$2 \cdot n$$$ appears in exactly one of the arrays.You need to perform a certain number of operations (possibly zero) so that both of the following conditions are satisfied: For each $$$1 \leq i < n$$$, it holds that $$$a_i < a_{i + 1}$$$ and $$$b_i < b_{i + 1}$$$.  For each $$$1 \leq i \leq n$$$, it holds that $$$a_i < b_i$$$. During each operation, you can perform exactly one of the following three actions: Choose an index $$$1 \leq i < n$$$ and swap the values $$$a_i$$$ and $$$a_{i + 1}$$$.  Choose an index $$$1 \leq i < n$$$ and swap the values $$$b_i$$$ and $$$b_{i + 1}$$$. Choose an index $$$1 \leq i \leq n$$$ and swap the values $$$a_i$$$ and $$$b_i$$$.You do not need to minimize the number of operations, but the total number must not exceed $$$1709$$$. Find any sequence of operations that satisfies both conditions.

## Input

Each test consists of multiple test cases. The first line contains a single integer $$$t$$$ ($$$1 \leq t \leq 100$$$) — the number of test cases. The description of the test cases follows.The first line of each test case contains a single integer $$$n$$$ ($$$1 \leq n \leq 40$$$) — the length of the arrays $$$a$$$ and $$$b$$$.The second line of each test case contains $$$n$$$ integers $$$a_1, a_2, \ldots, a_n$$$ ($$$1 \leq a_i \leq 2 \cdot n$$$).The third line of each test case contains $$$n$$$ integers $$$b_1, b_2, \ldots, b_n$$$ ($$$1 \leq b_i \leq 2 \cdot n$$$).It is guaranteed that each integer from $$$1$$$ to $$$2 \cdot n$$$ appears either in array $$$a$$$ or in array $$$b$$$.

## Output

For each test case, output the sequence of operations. In the first line for each test case, output the number of operations $$$k$$$. Note that $$$0 \leq k \leq 1709$$$. In the following $$$k$$$ lines for each test case, output the operations themselves: If you want to swap the values $$$a_i$$$ and $$$a_{i + 1}$$$, output two integers $$$1$$$ and $$$i$$$. Note that $$$1 \leq i < n$$$. If you want to swap the values $$$b_i$$$ and $$$b_{i + 1}$$$, output two integers $$$2$$$ and $$$i$$$. Note that $$$1 \leq i < n$$$. If you want to swap the values $$$a_i$$$ and $$$b_i$$$, output two integers $$$3$$$ and $$$i$$$. Note that $$$1 \leq i \leq n$$$.It can be shown that under the given constraints, a solution always exists.

## Example

### Input
```
611212121 34 221 43 236 5 43 2 135 3 42 6 1
```

### Output
```
0
1
3 1
1
2 1
1
3 2
9
3 1
3 2
3 3
1 1
2 1
2 2
1 2
1 1
2 1
6
2 2
1 1
1 2
2 1
3 1
3 2
```

## Note

In the first test case, $$$a_1 < b_1$$$, so no operations need to be applied. In the second test case, $$$a_1 > b_1$$$. After applying the operation, these values will be swapped. In the third test case, after applying the operation, $$$a = [1, 3]$$$ and $$$b = [2, 4]$$$. In the fourth test case, after applying the operation, $$$a = [1, 2]$$$ and $$$b = [3, 4]$$$.