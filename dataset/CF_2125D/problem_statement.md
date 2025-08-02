# D. Segments Covering

**Time limit:** 2 seconds
**Memory limit:** 256 megabytes
**Input:** standard input
**Output:** standard output

## Problem Statement

There is a linear strip divided into $$$m$$$ cells, numbered from $$$1$$$ to $$$m$$$ from left to right.You are given $$$n$$$ segments. Each segment is defined by four numbers: $$$l$$$, $$$r$$$, $$$p$$$ and $$$q$$$ — the segment covers cells from $$$l$$$ to $$$r$$$ inclusively and exists with probability $$$\frac{p}{q}$$$ (independently).Your task is to calculate the probability that each cell is covered by exactly one segment.

## Input

The first line contains two integers $$$n$$$ and $$$m$$$ ($$$1 \le n, m \le 2 \cdot 10^5$$$).Then $$$n$$$ lines follow. The $$$i$$$-th of them contains four integers $$$l_i$$$, $$$r_i$$$, $$$p_i$$$ and $$$q_i$$$ ($$$1 \le l_i \le r_i \le m$$$; $$$1 \le p_i < q_i < 998244353$$$).

## Output

Print a single integer — the probability that each cell is covered by exactly one segment, taken modulo $$$998244353$$$.Formally, the probability can be expressed as an irreducible fraction $$$\frac{x}{y}$$$. You have to print the value of $$$x \cdot y^{-1} \bmod 998244353$$$, where $$$y^{-1}$$$ is an integer such that $$$y \cdot y^{-1} \bmod 998244353 = 1$$$.

## Examples

### Input
```
3 31 2 1 33 3 1 21 3 2 3
```

### Output
```
610038216
```

## Note

In the first example, the probability is equal to $$$\frac{5}{18}$$$.