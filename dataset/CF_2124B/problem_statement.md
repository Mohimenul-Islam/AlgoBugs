# B. Minimise Sum

**Time limit:** 1.5 seconds
**Memory limit:** 256 megabytes
**Input:** standard input
**Output:** standard output

## Problem Statement

This problem differs from problem G. In this problem, you must output the minimum sum of prefix minimums after at most one operation.You are given an array $$$a$$$ of length $$$n$$$, with elements satisfying $$$\boldsymbol{0 \le a_i \le n}$$$. You can perform the following operation at most once:  Choose two indices $$$i$$$ and $$$j$$$ such that $$$i < j$$$. Set $$$a_i := a_i + a_j$$$. Then, set $$$a_j = 0$$$. Output the minimum possible value of $$$\min(a_1) + \min(a_1,a_2) + \ldots + \min(a_1, a_2, \ldots, a_n)$$$ that you can get.

## Input

Each test contains multiple test cases. The first line contains the number of test cases $$$t$$$ ($$$1 \le t \le 10^4$$$). The description of the test cases follows. The first line of each test case contains an integer $$$n$$$ ($$$2 \leq n \leq 2\cdot 10^5$$$) — the length of $$$a$$$.The following line contains $$$n$$$ space-separated integers $$$a_1, a_2, \ldots, a_n$$$ ($$$0 \le a_i \le n$$$) — denoting the array $$$a$$$.It is guaranteed that the sum of $$$n$$$ over all test cases does not exceed $$$2\cdot 10^5$$$.

## Output

For each test case, output an integer on a new line, the minimum possible value of $$$\min(a_1) + \min(a_1,a_2) + \ldots + \min(a_1, a_2, \ldots, a_n)$$$.

## Example

### Input
```
321 231 2 343 0 2 3
```

### Output
```
2
2
3
```

## Note

In the second test case, it is optimal to perform the operation with $$$i=2$$$ and $$$j=3$$$.In the third test case, it is optimal to not perform any operations. The answer is $$$3$$$.