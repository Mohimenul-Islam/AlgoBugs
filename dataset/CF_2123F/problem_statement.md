# F. Minimize Fixed Points

**Time limit:** 3 seconds
**Memory limit:** 256 megabytes
**Input:** standard input
**Output:** standard output

## Problem Statement

Call a permutation$$$^{\text{∗}}$$$ $$$p$$$ of length $$$n$$$ good if $$$\gcd(p_i, i)$$$$$$^{\text{†}}$$$ $$$ > 1$$$ for all $$$2 \leq i \leq n$$$. Find a good permutation with the minimum number of fixed points$$$^{\text{‡}}$$$ across all good permutations of length $$$n$$$. If there are multiple such permutations, print any of them.$$$^{\text{∗}}$$$ A permutation of length $$$n$$$ is an array that contains every integer from $$$1$$$ to $$$n$$$ exactly once, in any order. $$$^{\text{†}}$$$$$$\gcd(x, y)$$$ denotes the greatest common divisor (GCD) of $$$x$$$ and $$$y$$$.$$$^{\text{‡}}$$$A fixed point of a permutation $$$p$$$ is an index $$$j$$$ ($$$1\leq j\leq n$$$) such that $$$p_j = j$$$.

## Input

The first line contains an integer $$$t$$$ ($$$1 \leq t \leq 10^4$$$)  — the number of test cases.The only line of each test case contains an integer $$$n$$$ ($$$2 \leq n \leq 10^5$$$) — the length of the permutation.It is guaranteed that the sum of $$$n$$$ over all test cases does not exceed $$$10^5$$$.

## Output

For each test case, output on a single line an example of a good permutation of length $$$n$$$ with the minimum number of fixed points.

## Example

### Input
```
423613
```

### Output
```
1 2
1 2 3
1 4 6 2 5 3
1 12 9 6 10 8 7 4 3 5 11 2 13
```

## Note

In the third sample, we construct the permutation $$$i$$$$$$p_i$$$$$$\gcd(p_i, i)$$$$$$1$$$$$$1$$$$$$1$$$$$$2$$$$$$4$$$$$$2$$$$$$3$$$$$$6$$$$$$3$$$$$$4$$$$$$2$$$$$$2$$$$$$5$$$$$$5$$$$$$5$$$$$$6$$$$$$3$$$$$$3$$$ Then we see that $$$\gcd(p_i, i) > 1$$$ for all $$$2\leq i\leq 6$$$. Furthermore, we see that there are only two fixed points, namely, $$$1$$$ and $$$5$$$. It can be shown that it is impossible to build a good permutation of length $$$6$$$ with fewer fixed points.