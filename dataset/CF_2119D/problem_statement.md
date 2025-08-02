# D. Token Removing

**Time limit:** 2 seconds
**Memory limit:** 256 megabytes
**Input:** standard input
**Output:** standard output

## Problem Statement

r-906 & Hatsune Miku - All I Can See Is You Define a sequence of integers $$$a$$$ valid if and only if $$$\forall 1 \le i \le n, 0 \le a_i \le i$$$.Define the weight $$$f(a)$$$ of a valid sequence $$$a$$$ of length $$$n$$$:  Initially, a token is placed at each integer point in the closed segment $$$[1, n]$$$ on the number axis.  Perform $$$n$$$ operations in sequence. During the $$$i$$$-th operation, if $$$a_i \ne 0$$$, remove a token in the closed segment $$$[a_i, i]$$$ that has not been removed; otherwise, do nothing.  $$$f(a)$$$ is the number of ways to remove tokens. Two ways are considered different if there exists a $$$t$$$ such that the positions of the tokens removed by the two ways are different at the $$$t$$$-th operation. For example, $$$f([0, 2, 1]) = 2$$$, because we can remove tokens on $$$2, 1$$$ or $$$2, 3$$$ in sequence.JT gives you two integers $$$n, m$$$ and asks you to find the sum of the weights over all $$$(n + 1)!$$$ valid sequences of length $$$n$$$. Since the answer may be too large, print it modulo $$$m$$$.

## Input

Each test contains multiple test cases. The first line contains the number of test cases $$$t$$$ ($$$1 \le t \le 1000$$$). The description of the test cases follows. The only line of each test case contains two integers $$$n$$$ and $$$m$$$ ($$$1 \le n \le 5000, 10^8 \le m \le 1.01 \cdot 10^9$$$) — the length of valid sequences, and the modulus.It is guaranteed that the sum of $$$n^2$$$ over all test cases does not exceed $$$2.5 \cdot 10^7$$$.

## Output

For each test case, output an integer — the sum of the weights over all $$$(n + 1)!$$$ valid sequences of length $$$n$$$, modulo $$$m$$$.

## Example

### Input
```
61 10000000072 10000000073 10000000074 10000000075 1000000007114 514191981
```

### Output
```
2
7
37
273
2672
393775292
```

## Note

In the first test case, valid sequences are $$$[0]$$$ and $$$[1]$$$, and the answer is $$$f([0]) + f([1]) = 1 + 1 = 2$$$.In the second test case, valid sequences are $$$[0, 0], [0, 1], [0, 2], [1, 0], [1, 1], [1, 2]$$$. The weight of $$$[0, 1]$$$ is $$$2$$$, and the others are $$$1$$$, so the answer is $$$5 \cdot 1 + 1 \cdot 2 = 7$$$.