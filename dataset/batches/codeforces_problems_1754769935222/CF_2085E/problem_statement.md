# E. Serval and Modulo

**Time limit:** 2 seconds
**Memory limit:** 512 megabytes
**Input:** standard input
**Output:** standard output

## Problem Statement

There is an array $$$a$$$ consisting of $$$n$$$ non-negative integers and a magic number $$$k$$$ ($$$k\ge 1$$$, $$$k$$$ is an integer). Serval has constructed another array $$$b$$$ of length $$$n$$$, where $$$b_i = a_i \bmod k$$$ holds$$$^{\text{∗}}$$$ for all $$$1\leq i\leq n$$$. Then, he shuffled $$$b$$$.You are given the two arrays $$$a$$$ and $$$b$$$. Find a possible magic number $$$k$$$. However, there is a small possibility that Serval fooled you, and such an integer does not exist. In this case, output $$$-1$$$.It can be shown that, under the constraints of the problem, if such an integer $$$k$$$ exists, then there exists a valid answer no more than $$$10^9$$$. And you need to guarantee that $$$k\le 10^9$$$ in your output.$$$^{\text{∗}}$$$$$$a_i \bmod k$$$ denotes the remainder from dividing $$$a_i$$$ by $$$k$$$.

## Input

Each test contains multiple test cases. The first line contains the number of test cases $$$t$$$ ($$$1 \le t \le 10^4$$$). The description of the test cases follows. The first line of each test case contains an integer $$$n$$$ ($$$1\leq n\leq 10^4$$$) — the length of the array $$$a$$$.The second line contains $$$n$$$ integers $$$a_1, a_2, \ldots, a_n$$$ ($$$0\leq a_i\leq 10^6$$$) — the elements of the array $$$a$$$.The third line contains $$$n$$$ integers $$$b_1, b_2, \ldots, b_n$$$ ($$$0\leq b_i\leq 10^6$$$) — the elements of the array $$$b$$$.It is guaranteed that the sum of $$$n$$$ over all test cases does not exceed $$$10^4$$$.

## Output

For each test case, output a single integer $$$k$$$ ($$$1\leq k\leq 10^9$$$) — the magic number you found. Print $$$-1$$$ if it is impossible to find such an integer.If there are multiple answers, you may print any of them.

## Example

### Input
```
543 5 2 70 1 1 153 1 5 2 41 2 3 4 562 3 4 7 8 91 2 3 6 7 8521 22 25 28 200 1 2 1 061 1 2 3 5 80 0 1 1 0 0
```

### Output
```
2
31415926
-1
4
-1
```

## Note

In the first test case, if $$$k\ge 3$$$, then $$$2=a_3\bmod k$$$ should be in the array $$$b$$$, which leads to a contradiction. For $$$k = 1$$$, $$$[a_1\bmod k, a_2\bmod k, a_3\bmod k, a_4 \bmod k] = [0,0,0,0]$$$, which cannot be shuffled to $$$b$$$. For $$$k = 2$$$, $$$[a_1\bmod k, a_2\bmod k, a_3\bmod k, a_4 \bmod k] = [1,1,0,1]$$$, which can be shuffled to $$$b$$$. Thus, the only possible answer is $$$k=2$$$.In the second test case, note that $$$b$$$ can be obtained by shuffling $$$a$$$. Thus, all integers between $$$6$$$ and $$$10^9$$$ are possible answers.In the third test case, it can be shown that such $$$k$$$ does not exist. Got fooled by Serval!