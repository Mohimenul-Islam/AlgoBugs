# C. Leftmost Below

**Time limit:** 2 seconds
**Memory limit:** 256 megabytes
**Input:** standard input
**Output:** standard output

## Problem Statement

Consider an array $$$a_1, \ldots, a_n$$$. Initially, $$$a_i = 0$$$ for every $$$i$$$.You can do operations of the following form.   You choose an integer $$$x$$$ greater than $$$\min(a)$$$.  Then, $$$i$$$ is defined as the minimum index such that $$$a_i < x$$$. In other words, $$$i$$$ is the unique integer between $$$1$$$ and $$$n$$$ inclusive such that $$$a_i < x$$$ and $$$a_j \geq x$$$ for every $$$1 \leq j \leq i-1$$$.  Finally, $$$a_i$$$ is incremented by $$$x$$$. For example, if $$$a = [6, 8, 2, 1]$$$ and you choose $$$x = 6$$$, then $$$i$$$ will be equal to $$$3$$$ (since $$$a_1 \geq 6$$$, $$$a_2 \geq 6$$$, and $$$a_3 < 6$$$) and $$$a$$$ will become $$$[6, 8, 8, 1]$$$.You can do as many operations as you want. Can you reach a target array $$$b_1, \ldots, b_n$$$?

## Input

Each test contains multiple test cases. The first line contains the number of test cases $$$t$$$ ($$$1 \le t \le 10\,000$$$). The description of the test cases follows. The first line of each test case contains a single integer $$$n$$$ ($$$2 \leq n \leq 200\,000$$$).The second line of each test case contains $$$n$$$ integers $$$b_1, b_2, \ldots, b_n$$$ ($$$1 \le b_i \le 10^9$$$).The sum of $$$n$$$ over all test cases does not exceed $$$200\,000$$$.

## Output

For each test case, print YES if you can reach the target array and NO otherwise.You can output the answer in any case (upper or lower). For example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as positive responses.

## Example

### Input
```
445 6 1 133 1 2340 60 9021 1
```

### Output
```
YES
NO
NO
YES
```

## Note

In the first test case, we can do the following sequence of operations:   we choose $$$x=2$$$, $$$a$$$ becomes $$$[2, 0, 0, 0]$$$  we choose $$$x=2$$$, $$$a$$$ becomes $$$[2, 2, 0, 0]$$$  we choose $$$x=3$$$, $$$a$$$ becomes $$$[5, 2, 0, 0]$$$  we choose $$$x=4$$$, $$$a$$$ becomes $$$[5, 6, 0, 0]$$$  we choose $$$x=1$$$, $$$a$$$ becomes $$$[5, 6, 1, 0]$$$  we choose $$$x=1$$$, $$$a$$$ becomes $$$[5, 6, 1, 1]$$$ In the second test case, we can prove there is no way to reach $$$[3, 1, 2]$$$.