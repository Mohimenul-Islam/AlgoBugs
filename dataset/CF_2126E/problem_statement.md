# E. G-C-D, Unlucky!

**Time limit:** 2 seconds
**Memory limit:** 256 megabytes
**Input:** standard input
**Output:** standard output

## Problem Statement

Two arrays $$$p$$$ and $$$s$$$ of length $$$n$$$ are given, where $$$p$$$ is the prefix GCD$$$^{\text{∗}}$$$ of some array $$$a$$$, and $$$s$$$ is the suffix GCD of the same array $$$a$$$. In other words, if the array $$$a$$$ existed, then for each $$$1 \le i \le n$$$, the following equalities would hold both:   $$$p_i = \gcd(a_1, a_2, \dots, a_i)$$$  $$$s_i = \gcd(a_i, a_{i+1}, \dots, a_n)$$$.  Determine whether there exists such an array $$$a$$$ for which the given arrays $$$p$$$ and $$$s$$$ can be obtained.$$$^{\text{∗}}$$$$$$\gcd(x, y)$$$ denotes the greatest common divisor (GCD) of integers $$$x$$$ and $$$y$$$.

## Input

The first line contains an integer $$$t$$$ ($$$1 \le t \le 10^4$$$) — the number of test cases.Each test case consists of three lines:The first line of each test case contains a single integer $$$n$$$ ($$$1 \leq n \leq 10^5$$$) — the length of the array.The second line of each test case contains $$$n$$$ integers $$$p_1, p_2, \dots, p_n$$$ ($$$1 \leq p_i \le 10^9$$$) — the elements of the array.The third line of each test case contains $$$n$$$ integers $$$s_1, s_2, \dots, s_n$$$ ($$$1 \leq s_i \le 10^9$$$) — the elements of the array.It is guaranteed that the sum of all $$$n$$$ across all test cases does not exceed $$$10^5$$$.

## Output

For each test case, output "Yes" (without quotes) if there exists an array $$$a$$$ for which the given arrays $$$p$$$ and $$$s$$$ can be obtained, and "No" (without quotes) otherwise.You may output each letter in any case (lowercase or uppercase). For example, the strings "yEs", "yes", "Yes", and "YES" will be accepted as a positive answer.

## Example

### Input
```
5672 24 3 3 3 33 3 3 6 12 14431 2 34 5 65125 125 125 25 2525 25 25 25 754123 421 282 251125 1981 239 2233124 521 125125 121 121
```

### Output
```
YES
NO
YES
NO
NO
```

## Note

For the first test case, a possible array is: [$$$72,\ 24,\ 3,\ 6,\ 12,\ 144$$$].For the second test case, it can be shown that such arrays do not exist.For the third test case, there exists an array: [$$$125,\ 125,\ 125,\ 25,\ 75$$$].