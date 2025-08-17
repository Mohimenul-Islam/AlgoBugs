# D. Balanced Tree

**Time limit:** 3 seconds
**Memory limit:** 512 megabytes
**Input:** standard input
**Output:** standard output

## Problem Statement

You are given a tree$$$^{\text{∗}}$$$ with $$$n$$$ nodes and values $$$l_i, r_i$$$ for each node. You can choose an initial value $$$a_i$$$ satisfying $$$l_i\le a_i\le r_i$$$ for the $$$i$$$-th node. A tree is balanced if all node values are equal, and the value of a balanced tree is defined as the value of any node.In one operation, you can choose two nodes $$$u$$$ and $$$v$$$, and increase the values of all nodes in the subtree$$$^{\text{†}}$$$ of node $$$v$$$ by $$$1$$$ while considering $$$u$$$ as the root of the entire tree. Note that $$$u$$$ may be equal to $$$v$$$.Your goal is to perform a series of operations so that the tree becomes balanced. Find the minimum possible value of the tree after performing these operations. Note that you don't need to minimize the number of operations.$$$^{\text{∗}}$$$A tree is a connected graph without cycles. $$$^{\text{†}}$$$Node $$$w$$$ is considered in the subtree of node $$$v$$$ if any path from root $$$u$$$ to $$$w$$$ must go through $$$v$$$.

## Input

The first line of input contains a single integer $$$t$$$ ($$$1 \leq t \leq 10^5$$$) — the number of input test cases.The first line of each test case contains one integer $$$n$$$ ($$$1 \le n \le 2\cdot 10^5$$$) — the number of nodes in the tree.Then $$$n$$$ lines follow. The $$$i$$$-th line contains two integers $$$l_i,r_i$$$ ($$$0\le l_i \le r_i\le 10^9$$$) — the constraint of the value of the $$$i$$$-th node.The next $$$n-1$$$ lines contain the edges of the tree. The $$$i$$$-th line contains two integers $$$u_i,v_i$$$ ($$$1\le u_i,v_i \le n$$$, $$$u_i \neq v_i$$$) — an edge connecting $$$u_i$$$ and $$$v_i$$$. It is guaranteed that the given edges form a tree.It is guaranteed that the sum of $$$n$$$ over all test cases does not exceed $$$2\cdot 10^5$$$.

## Output

For each test case, output a single integer — the minimum possible value that all $$$a_i$$$ can be made equal to after performing the operations. It can be shown that the answer always exists.

## Example

### Input
```
640 116 60 05 52 13 14 371 10 50 52 22 22 22 21 21 32 42 53 63 741 11 11 10 01 42 43 470 200 200 200 203 34 45 51 21 31 42 53 64 751000000000 10000000000 01000000000 10000000000 01000000000 10000000003 22 11 44 5621 8857 8198 9961 7615 5023 672 13 24 35 36 4
```

### Output
```
11
3
3
5
3000000000
98
```

## Note

In the first test case, you can choose $$$a=[6,6,0,5]$$$.You can perform the following operations to make all $$$a_i$$$ equal:  Choose $$$u=4$$$, $$$v=3$$$ and perform the operation $$$5$$$ times.  Choose $$$u=1$$$, $$$v=3$$$ and perform the operation $$$6$$$ times. The complete process is shown as follows (where the numbers inside the parentheses are elements of $$$a$$$):It can be proven that this is the optimal solution.