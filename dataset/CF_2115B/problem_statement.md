# B. Gellyfish and Camellia Japonica

**Time limit:** 2 seconds
**Memory limit:** 512 megabytes
**Input:** standard input
**Output:** standard output

## Problem Statement

Gellyfish has an array of $$$n$$$ integers $$$c_1, c_2, \ldots, c_n$$$. In the beginning, $$$c = [a_1, a_2, \ldots, a_n]$$$.Gellyfish will make $$$q$$$ modifications to $$$c$$$.For $$$i = 1,2,\ldots,q$$$, Gellyfish is given three integers $$$x_i$$$, $$$y_i$$$, and $$$z_i$$$ between $$$1$$$ and $$$n$$$. Then Gellyfish will set $$$c_{z_i} := \min(c_{x_i}, c_{y_i})$$$.After the $$$q$$$ modifications, $$$c = [b_1, b_2, \ldots, b_n]$$$.Now Flower knows the value of $$$b$$$ and the value of the integers $$$x_i$$$, $$$y_i$$$, and $$$z_i$$$ for all $$$1 \leq i \leq q$$$, but she doesn't know the value of $$$a$$$.Flower wants to find any possible value of the array $$$a$$$ or report that no such $$$a$$$ exists.If there are multiple possible values of the array $$$a$$$, you may output any of them.

## Input

Each test contains multiple test cases. The first line contains the number of test cases $$$t$$$ ($$$1 \le t \le 10^4$$$). The description of the test cases follows. The first line of each test case contains two integers $$$n$$$ and $$$q$$$ ($$$1 \leq n, q \leq 3 \cdot 10^5$$$) — the size of the array and the number of modifications.The second line of each test case contains $$$n$$$ integers $$$b_1, b_2, \ldots, b_n$$$ ($$$1 \leq b_i \leq 10^9$$$) — the value of the array $$$c$$$ after the $$$q$$$ modifications.The following $$$q$$$ lines each contain three integers $$$x_i$$$, $$$y_i$$$, and $$$z_i$$$ ($$$1 \leq x_i, y_i, z_i \leq n$$$) — describing the $$$i$$$-th modification.It is guaranteed that the sum of $$$n$$$ and the sum of $$$q$$$ over all test cases does not exceed $$$3 \cdot 10^5$$$.

## Output

For each test case, if $$$a$$$ exists, output $$$n$$$ integers $$$a_1, a_2, \ldots, a_n$$$ ($$$0 \leq a_i \leq 10^9$$$) in a single line. Otherwise, output "-1" in a single line.If there are multiple solutions, print any of them.

## Example

### Input
```
32 11 22 1 23 21 2 32 3 21 2 16 41 2 2 3 4 55 6 64 5 53 4 42 3 3
```

### Output
```
-1
1 2 3 
1 2 3 4 5 5
```

## Note

In the first test case, based on the given sequence of modifications, we know that $$$b_1 = a_1$$$ and $$$b_2 = \min(a_1, a_2)$$$. Therefore, it is necessary that $$$b_2 \leq b_1$$$. However, for the given $$$b$$$, we have $$$b_1<b_2$$$. Therefore, there is no solution.In the second test case, we can see that the given $$$c$$$ becomes $$$b$$$ from $$$a$$$ after the given modifications, and $$$c$$$ is not changed at each modification.