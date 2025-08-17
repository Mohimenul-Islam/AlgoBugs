# C. Divine Tree

**Time limit:** 2 seconds
**Memory limit:** 256 megabytes
**Input:** standard input
**Output:** standard output

## Problem Statement

Harshith attained enlightenment in Competitive Programming by training under a Divine Tree. A divine tree is a rooted tree$$$^{\text{∗}}$$$ with $$$n$$$ nodes, labelled from $$$1$$$ to $$$n$$$. The divineness of a node $$$v$$$, denoted $$$d(v)$$$, is defined as the smallest node label on the unique simple path from the root to node $$$v$$$.Aryan, being a hungry Competitive Programmer, asked Harshith to pass on the knowledge. Harshith agreed on the condition that Aryan would be given two positive integers $$$n$$$ and $$$m$$$, and he had to construct a divine tree with $$$n$$$ nodes such that the total divineness of the tree is $$$m$$$, i.e., $$$\displaystyle\sum\limits_{i=1}^n d(i)=m$$$. If no such tree exists, Aryan must report that it is impossible.Desperate for knowledge, Aryan turned to you for help in completing this task. As a good friend of his, help him solve the task.$$$^{\text{∗}}$$$A tree is a connected graph without cycles.  A rooted tree is a tree where one vertex is special and called the root.

## Input

Each test contains multiple test cases. The first line contains the number of test cases $$$t$$$ ($$$1 \le t \le 10^4$$$). The description of the test cases follows. The first line of each test case contains two integers $$$n$$$ and $$$m$$$ ($$$1 \le n \le 10^6$$$, $$$1 \le m \le 10^{12}$$$).It is guaranteed that the sum of $$$n$$$ over all test cases does not exceed $$$10^6$$$.

## Output

For each test case, output a single integer $$$k$$$ in one line — the root of the tree.Then $$$n-1$$$ lines follow, each containing a description of an edge of the tree — a pair of positive integers $$$u_i,v_i$$$ ($$$1\le u_i,v_i\le n$$$, $$$u_i\ne v_i$$$), denoting the $$$i$$$-th edge connects vertices $$$u_i$$$ and $$$v_i$$$.The edges and vertices of the edges can be printed in any order. If there are multiple solutions, print any of them.If there is no solution, print "-1" instead.

## Example

### Input
```
21 24 6
```

### Output
```
-1
3
3 1
1 2
2 4
```

## Note

In the first test case, there is a single node with a value of $$$1$$$, so getting a sum of $$$2$$$ is impossible.In the second test case, getting a sum of $$$6$$$ is possible with the given tree rooted at $$$3$$$.