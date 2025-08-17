# D. Sum of LDS

**Time limit:** 2 seconds
**Memory limit:** 256 megabytes
**Input:** standard input
**Output:** standard output

## Problem Statement

You're given a permutation$$$^{\text{∗}}$$$ $$$p_1, \ldots, p_n$$$ such that $$$\max(p_i, p_{i+1}) > p_{i+2}$$$ for all $$$1 \leq i \leq n-2$$$.Compute the sum of the length of the longest decreasing subsequence$$$^{\text{†}}$$$ of the subarray $$$[p_l, p_{l+1}, \ldots, p_r]$$$ over all pairs $$$1 \leq l \leq r \leq n$$$.$$$^{\text{∗}}$$$A permutation of length $$$n$$$ is an array consisting of $$$n$$$ distinct integers from $$$1$$$ to $$$n$$$ in arbitrary order. For example, $$$[2,3,1,5,4]$$$ is a permutation, but $$$[1,2,2]$$$ is not a permutation ($$$2$$$ appears twice in the array), and $$$[1,3,4]$$$ is also not a permutation ($$$n=3$$$ but there is $$$4$$$ in the array). $$$^{\text{†}}$$$Given an array $$$b$$$ of size $$$|b|$$$, a decreasing subsequence of length $$$k$$$ is a sequence of indices $$$i_1, \ldots, i_k$$$ such that:  $$$1 \leq i_1 < i_2 < \ldots < i_k \leq |b|$$$  $$$b_{i_1} > b_{i_2} > \ldots > b_{i_k}$$$

## Input

Each test contains multiple test cases. The first line contains the number of test cases $$$t$$$ ($$$1 \le t \le 10\,000$$$). The description of the test cases follows. The first line of each test case contains a single integer $$$n$$$ ($$$3 \leq n \leq 500\,000$$$).The second line of each test case contains $$$n$$$ integers $$$p_1, p_2, \ldots, p_n$$$ ($$$1 \le p_i \le n$$$, $$$p_i$$$ are pairwise distinct).It is guaranteed that $$$\max(p_i, p_{i+1}) > p_{i+2}$$$ for all $$$1 \leq i \leq n-2$$$.The sum of $$$n$$$ over all test cases does not exceed $$$500\,000$$$.

## Output

For each test case, output the sum over all subarrays of the length of its longest decreasing subsequence.

## Example

### Input
```
433 2 144 3 1 266 1 5 2 4 332 3 1
```

### Output
```
10
17
40
8
```

## Note

For any array $$$a$$$, we define $$$\text{LDS}(a)$$$ as the length of the longest decreasing subsequence of $$$a$$$.In the first test case, all subarrays are decreasing. In the second one, we have $$$\text{LDS}([4]) = \text{LDS}([3]) = \text{LDS}([1]) = \text{LDS}([2]) = 1$$$ $$$\text{LDS}([4,3]) = \text{LDS}([3,1]) = 2, \text{LDS}([1, 2]) = 1$$$ $$$\text{LDS}([4,3,1]) = 3, \text{LDS}([3,1,2]) = 2$$$ $$$\text{LDS}([4,3,1,2]) = 3$$$So the answer is $$$1+1+1+1+2+2+1+3+2+3=17$$$.