# B. Deque Process

**Time limit:** 1.5 seconds
**Memory limit:** 256 megabytes
**Input:** standard input
**Output:** standard output

## Problem Statement

We say that an array $$$a$$$ of size $$$n$$$ is bad if and only if there exists $$$1 \leq i \leq n - 4$$$ such that one of the following conditions holds:  $$$a_i < a_{i+1} < a_{i+2} < a_{i+3} < a_{i+4}$$$  $$$a_i > a_{i+1} > a_{i+2} > a_{i+3} > a_{i+4}$$$ An array is good if and only if it's not bad. For example:   $$$a = [3, \color{red}{1, 2, 4, 5, 6}]$$$ is bad because $$$a_2 < a_3 < a_4 < a_5 < a_6$$$.  $$$a = [\color{red}{7, 6, 5, 4, 1}, 2, 3]$$$ is bad because $$$a_1 > a_2 > a_3 > a_4 > a_5$$$.  $$$a = [7, 6, 5, 1, 2, 3, 4]$$$ is good. You're given a permutation$$$^{\text{∗}}$$$ $$$p_1, p_2, \ldots, p_n$$$.You must perform $$$n$$$ turns. At each turn, you must remove either the leftmost or the rightmost remaining element in $$$p$$$. Let $$$q_i$$$ be the element removed at the $$$i$$$-th turn.Choose which element to remove at each turn so that the resulting array $$$q$$$ is good. We can show that under the given constraints, it's always possible.$$$^{\text{∗}}$$$A permutation of length $$$n$$$ is an array consisting of $$$n$$$ distinct integers from $$$1$$$ to $$$n$$$ in arbitrary order. For example, $$$[2,3,1,5,4]$$$ is a permutation, but $$$[1,2,2]$$$ is not a permutation ($$$2$$$ appears twice in the array), and $$$[1,3,4]$$$ is also not a permutation ($$$n=3$$$ but there is $$$4$$$ in the array).

## Input

Each test contains multiple test cases. The first line contains the number of test cases $$$t$$$ ($$$1 \le t \le 10\,000$$$). The description of the test cases follows. The first line of each test case contains a single integer $$$n$$$ ($$$5 \leq n \leq 100\,000$$$) — the length of the array.The second line of each test case contains $$$n$$$ integers $$$p_1, p_2, \ldots, p_n$$$ ($$$1 \leq p_i \leq n$$$, $$$p_i$$$ are pairwise distinct) — elements of the permutation.It is guaranteed that the sum of $$$n$$$ over all test cases doesn't exceed $$$200\,000$$$.

## Output

For each test case, you must output a string $$$s$$$ of length $$$n$$$. For every $$$1 \leq i \leq n$$$, at the $$$i$$$-th turn:   $$$s_i = \texttt{L}$$$ means that you removed the leftmost element of $$$p$$$  $$$s_i = \texttt{R}$$$ means that you removed the rightmost element of $$$p$$$ We can show that an answer always exists. If there are multiple solutions, print any of them.

## Example

### Input
```
671 2 3 4 5 6 791 3 6 8 9 7 5 4 2121 2 11 3 6 4 7 8 12 5 10 964 1 2 5 6 351 2 3 5 495 1 8 6 2 7 9 4 3
```

### Output
```
RRRLLLL
LLRRLLRRL
LLLLLLLLLLLL
LLLLLL
LLLLL
LLLLLLLLL
```

## Note

In the first test case, the sequence $$$\color{blue}{\texttt{RRR}}\color{red}{\texttt{LLLL}}$$$ results in $$$q = [\color{blue}{7}, \color{blue}{6}, \color{blue}{5}, \color{red}{1}, \color{red}{2}, \color{red}{3}, \color{red}{4}]$$$.In the second test case, the sequence $$$\color{red}{\texttt{LL}}\color{blue}{\texttt{RR}}\color{red}{\texttt{LL}}\color{blue}{\texttt{RR}}\color{red}{\texttt{L}}$$$ results in $$$q = [\color{red}{1}, \color{red}{3}, \color{blue}{2}, \color{blue}{4}, \color{red}{6}, \color{red}{8}, \color{blue}{5}, \color{blue}{7}, \color{red}{9}]$$$.