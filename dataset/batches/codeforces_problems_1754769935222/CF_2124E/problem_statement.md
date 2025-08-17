# E. Make it Zero

**Time limit:** 2 seconds
**Memory limit:** 256 megabytes
**Input:** standard input
**Output:** standard output

## Problem Statement

You are given an array $$$a$$$, consisting of $$$n$$$ positive integers. You are allowed to do the following operation:   Select an array $$$b$$$ of size $$$n$$$ such that the following properties hold:  $$$0 \leq b_i \leq a_i$$$ for each $$$1 \leq i \leq n$$$  There exists an index $$$1\leq i < n$$$ such that $$$b_1+b_2+\ldots+b_i=b_{i+1}+b_{i+2}+\ldots+b_n$$$. That is, the sum of the prefix of length $$$i$$$ is equal to the sum of the suffix of length $$$n-i$$$.   Then, subtract $$$b_i$$$ from $$$a_i$$$ for each $$$1 \leq i \leq n$$$. Your task is to change all the elements to $$$0$$$. Find the minimum number of operations required. Then, output a way to perform the operations. If it is impossible to change all the elements of $$$a$$$ to $$$0$$$ no matter how many operations are used, print $$$-1$$$ instead. It can be shown that under the constraints of this problem, the smallest number of operations required is at most $$$17$$$.

## Input

Each test contains multiple test cases. The first line contains the number of test cases $$$t$$$ ($$$1 \le t \le 10^4$$$). The description of the test cases follows. The first line of each test case contains an integer $$$n$$$ ($$$2 \leq n \leq 5\cdot 10^4$$$) — the length of the array $$$a$$$.The second line of each test case contains $$$n$$$ integers $$$a_1,a_2,\ldots,a_n$$$ ($$$1 \leq a_i \leq 10^{12}$$$) — denoting the array $$$a$$$.It is guaranteed that the sum of $$$n$$$ over all test cases does not exceed $$$5\cdot 10^4$$$.

## Output

For each test case, output $$$-1$$$ if there is no solution. Otherwise, first output an integer $$$s$$$ ($$$1 \leq s \leq 17$$$) – the minimum number of operations to change all the elements of $$$a$$$ to $$$0$$$.Then, in the next $$$s$$$ lines, output $$$n$$$ integers in each line $$$b_1,b_2,\ldots,b_n (0 \leq b_i \leq a_i)$$$ — denoting the array $$$b$$$ for each operation.After performing the operations, all the elements of $$$a$$$ should be changed to $$$0$$$.

## Example

### Input
```
331 2 322 545 3 1 5
```

### Output
```
1
1 2 3
-1
2
3 1 1 1
2 2 0 4
```

## Note

In the first test case, we can simply choose $$$b=a$$$ in our operation. This is valid because $$$b_1+b_2=b_3$$$. In the second test case, it can be proven that it is impossible to change all the elements of $$$a$$$ to $$$0$$$.