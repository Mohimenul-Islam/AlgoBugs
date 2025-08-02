# E. MEX Count

**Time limit:** 3 seconds
**Memory limit:** 256 megabytes
**Input:** standard input
**Output:** standard output

## Problem Statement

Define the $$$\mathrm{MEX}$$$ (minimum excluded value) of an array to be the smallest nonnegative integer not present in the array. For example,  $$$\mathrm{MEX}([2, 2, 1]) = 0$$$ because $$$0$$$ is not in the array.  $$$\mathrm{MEX}([3, 1, 0, 1]) = 2$$$ because $$$0$$$ and $$$1$$$ are in the array but $$$2$$$ is not.  $$$\mathrm{MEX}([0, 3, 1, 2]) = 4$$$ because $$$0$$$, $$$1$$$, $$$2$$$, and $$$3$$$ are in the array but $$$4$$$ is not. You are given an array $$$a$$$ of size $$$n$$$ of nonnegative integers.For all $$$k$$$ ($$$0\leq k \leq n$$$), count the number of possible values of $$$\mathrm{MEX}(a)$$$ after removing exactly $$$k$$$ values from $$$a$$$.

## Input

The first line contains an integer $$$t$$$ ($$$1\leq t\leq 10^4$$$)  — the number of test cases.The first line of each test case contains one integer $$$n$$$ ($$$1\leq n\leq 2\cdot 10^5$$$) — the size of the array $$$a$$$.The second line of each test case contains $$$n$$$ integers, $$$a_1,a_2,\dots,a_n$$$ ($$$0\leq a_i\leq n$$$).It is guaranteed that the sum of $$$n$$$ over all test cases does not exceed $$$2\cdot 10^5$$$.

## Output

For each test case, output a single line containing $$$n+1$$$ integers — the number of possible values of $$$\mathrm{MEX}(a)$$$ after removing exactly $$$k$$$ values, for $$$k=0,1,\dots,n$$$.

## Example

### Input
```
551 0 0 1 263 2 0 4 5 161 2 0 1 3 240 3 4 150 0 0 0 0
```

### Output
```
1 2 4 3 2 1
1 6 5 4 3 2 1
1 3 5 4 3 2 1
1 3 3 2 1
1 1 1 1 1 1
```

## Note

In the first sample, consider $$$k=1$$$. If you remove a $$$0$$$, then you get the following array: 1012 So we get $$$\mathrm{MEX}(a) = 3$$$. Alternatively, if you remove the $$$2$$$, then you get the following array: 1001 So we get $$$\mathrm{MEX}(a) = 2$$$. It can be shown that these are the only possible values of $$$\mathrm{MEX}(a)$$$ after removing exactly one value. So the output for $$$k=1$$$ is $$$2$$$.