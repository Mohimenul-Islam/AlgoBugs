# E1. Submedians (Easy Version)

**Time limit:** 3 seconds
**Memory limit:** 512 megabytes
**Input:** standard input
**Output:** standard output

## Problem Statement

This is the easy version of the problem. The only difference is that in this version, you are asked to find a subarray only for the maximum submedian.You can make hacks only if both versions of the problem are solved.An integer $$$v$$$ is a median of an array $$$b$$$ of length $$$m$$$ if and only if:   $$$v$$$ is greater than or equal to at least $$$\lceil \frac{m}{2} \rceil$$$ elements of the array, and  $$$v$$$ is less than or equal to at least $$$\lceil \frac{m}{2} \rceil$$$ elements of the array.  For instance:   the only median of $$$[9, 3, 7]$$$ is $$$7$$$,  the medians of $$$[5, 3, 7, 9]$$$ are $$$5$$$, $$$6$$$, and $$$7$$$, and  the only median of $$$[2, 2, 2]$$$ is $$$2$$$. You're given an integer $$$k$$$ and an array $$$a_1, \ldots, a_n$$$ of integers between $$$1$$$ and $$$n$$$.An integer $$$v$$$ from $$$1$$$ to $$$n$$$ is said to be a submedian if there exists at least one pair of indices $$$(l, r)$$$ such that   $$$1 \leq l \leq r \leq n$$$,  $$$r - l + 1 \geq k$$$,  $$$v$$$ is a median of the subarray $$$[a_l, \ldots, a_r]$$$. It can be proven that there always exists at least one submedian. Find the maximum submedian $$$v_\max$$$ and any corresponding pair of indices $$$(l, r)$$$.

## Input

Each test contains multiple test cases. The first line contains the number of test cases $$$t$$$ ($$$1 \le t \le 50\,000$$$). The description of the test cases follows. The first line of each test case contains two integers $$$n$$$ and $$$k$$$ ($$$1 \leq k \leq n \leq 300\,000$$$).The second line of each test case contains $$$n$$$ integers $$$a_1, a_2, \ldots, a_n$$$ ($$$1 \leq a_i \leq n$$$).It is guaranteed that the sum of $$$n$$$ over all test cases doesn't exceed $$$300\,000$$$.

## Output

For each test case, output three integers $$$v_\max$$$, $$$l$$$, and $$$r$$$ — the maximum submedian $$$v_\max$$$ and the bounds of a subarray of length at least $$$k$$$ ($$$r - l + 1 \geq k$$$) such that $$$v_\max$$$ is one of its medians.If there are many solutions, you can print any of them.

## Example

### Input
```
74 34 1 2 45 21 2 3 2 15 31 2 3 2 15 31 1 2 5 31 112 12 14 11 2 1 3
```

### Output
```
4 1 4
3 3 4
2 2 4
3 3 5
1 1 1
2 1 2
3 4 4
```

## Note

In the first test case, the subarrays of length at least $$$k = 3$$$ are   $$$(l = 1, r = 3)$$$: $$$[4, 1, 2]$$$ whose only median is $$$2$$$,  $$$(l = 2, r = 4)$$$: $$$[1, 2, 4]$$$ whose only median is $$$2$$$, and  $$$(l = 1, r = 4)$$$: $$$[4, 1, 2, 4]$$$ whose medians are $$$2$$$, $$$3$$$, and $$$4$$$. In the second test case, one possible output is $$$(l = 3, r = 4)$$$ whose medians are $$$2$$$ and $$$3$$$.Note that it can be proven that no subarray of length at least $$$2$$$ admits $$$4$$$ or $$$5$$$ as a median.