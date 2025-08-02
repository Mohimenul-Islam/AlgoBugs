# C. Subset Multiplication

**Time limit:** 3 seconds
**Memory limit:** 256 megabytes
**Input:** standard input
**Output:** standard output

## Problem Statement

Alice has an array $$$a$$$, consisting of $$$n$$$ positive integers. The array satisfies the beautiful property that $$$a_i$$$ divides $$$a_{i+1}$$$ for each $$$1 \leq i \leq n - 1$$$. Bob sees Alice's beautiful array and is jealous. To sabotage her, Bob first creates an array $$$b$$$ of size $$$n$$$ such that $$$b_i=a_i$$$ for each $$$1 \leq i \leq n$$$. Then, he chooses a positive integer $$$x$$$ and multiplies some (possibly none, possibly all) elements in $$$b$$$ by $$$x$$$. Formally, he chooses a (possibly-empty) subset $$$S\subseteq\{1,2,\ldots,n\}$$$, and for each $$$i\in S$$$, he sets $$$b_i:=b_i\cdot x$$$. You are given an array $$$b$$$, but you don't know array $$$a$$$ and the chosen number $$$x$$$. Please output any integer $$$x$$$ that Bob could choose, so that multiplying some subset of elements of the correct array $$$a$$$ by $$$x$$$ would result in array $$$b$$$. It is guaranteed that the answer exists. If there are multiple possible integers, you can output any of them.

## Input

Each test contains multiple test cases. The first line contains the number of test cases $$$t$$$ ($$$1 \le t \le 2\cdot10^5$$$). The description of the test cases follows. The first line of each test case contains an integer $$$n$$$ ($$$2 \leq n \leq 6\cdot10^5$$$) — the length of the array $$$b$$$.The second line of each test case contains $$$n$$$ integers $$$b_1,b_2,\ldots,b_n$$$ ($$$1 \leq b_i \leq 10^9$$$) — denoting the array $$$b$$$.It is guaranteed the array $$$b$$$ can be obtained from some beautiful array $$$a$$$ and some positive integer $$$x$$$ as described in the statements.It is guaranteed that the sum of $$$n$$$ over all test cases does not exceed $$$6\cdot 10^5$$$.

## Output

For each test case, output any possible value of $$$x$$$ ($$$1 \leq x \leq 10^9$$$) on a new line. It is guaranteed at least one value of $$$x$$$ exists.

## Example

### Input
```
422 431 1000000000 50000000044 8 4 8742 42 14 84 28 73080 255780
```

### Output
```
343
2
4
6
```

## Note

In the first test case, it is possible Bob selected $$$x=343$$$ and $$$S=\{\}$$$ (meaning he did not change the array $$$a$$$ at all). In the third test case, it is possible Bob selected $$$x=4$$$ and $$$S=\{1,2\}$$$, meaning he multiplied both $$$b_1$$$ and $$$b_2$$$ by $$$4$$$. The original array was $$$\{1,2,4,8\}$$$, which satisfies the required property.