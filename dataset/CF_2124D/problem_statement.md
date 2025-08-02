# D. Make a Palindrome

**Time limit:** 2 seconds
**Memory limit:** 256 megabytes
**Input:** standard input
**Output:** standard output

## Problem Statement

You are given an array $$$a$$$ of size $$$n$$$, and an integer $$$k$$$. You may perform the following operation any number of times:   Select two integers $$$l$$$ and $$$r$$$ $$$(1 \le l \le r \le |a|)$$$ such that $$$r-l+1 \geq k$$$.  Then, select an index $$$i$$$ such that $$$l\leq i \leq r$$$ where $$$a_i$$$ is the $$$k$$$-th smallest number out of the subarray $$$[a_l,a_{l+1},\ldots,a_r]$$$. If there are multiple possible $$$i$$$, you may select any. For example, consider $$$a = [1, 2, 2, 1, 3], l = 1, r = 5$$$ and $$$k = 3$$$, the possible candidates of $$$i$$$ are indices $$$2$$$ and $$$3$$$.  Then, delete $$$a_i$$$ from $$$a$$$, concatenating the remaining parts of the array. Determine if it is possible to get an array that is a palindrome$$$^{\text{∗}}$$$ after any number of operations. Note that an empty array is considered a palindrome. $$$^{\text{∗}}$$$An array $$$b=[b_1,b_2,\ldots,b_m]$$$ is a palindrome if for each $$$1 \leq i \leq m$$$, $$$b_i=b_{m+1-i}$$$.

## Input

Each test contains multiple test cases. The first line contains the number of test cases $$$t$$$ ($$$1 \le t \le 10^4$$$). The description of the test cases follows. The first line contains two integers $$$n$$$ and $$$k$$$ ($$$1 \leq k \leq n \leq 2\cdot 10^5$$$).The second line contains $$$n$$$ integers $$$a_1,a_2,\ldots,a_n$$$ ($$$1 \leq a_i \leq n$$$) — denoting the array $$$a$$$.It is guaranteed that the sum of $$$n$$$ over all test cases does not exceed $$$2\cdot 10^5$$$.

## Output

For each test case, output YES if it is possible to create a palindrome, and NO otherwise. You can output in any case (upper or lower). For example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as positive responses.

## Example

### Input
```
85 35 4 3 4 54 11 1 2 16 62 3 4 5 3 25 45 2 4 3 18 54 7 1 2 3 1 3 45 41 2 1 2 23 31 2 24 42 1 2 2
```

### Output
```
YES
YES
YES
NO
NO
YES
NO
YES
```

## Note

In the first test case, $$$a$$$ is already a palindrome.In the second test case, we can perform two operations as follows: $$$[\mathbf{1,1},2,1]\rightarrow [1,\mathbf{2},1]\rightarrow[1,1]$$$In the third test case, we can perform one operation as follows: $$$[\mathbf{2,3,4,5,3,2}]\rightarrow[2,3,4,3,2]$$$.In the fourth and fifth test cases, it can be shown it is impossible to create a palindrome no matter what operations are used.