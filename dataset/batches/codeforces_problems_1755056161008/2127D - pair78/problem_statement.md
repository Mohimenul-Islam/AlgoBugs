# D. Root was Built by Love, Broken by Destiny

**Time limit:** 2 seconds
**Memory limit:** 256 megabytes
**Input:** standard input
**Output:** standard output

## Problem Statement

Heartfall River runs horizontally through Destinyland and divides it into the northern and southern sides.Engineer Root wants to build $$$n$$$ houses along the river, numbered from $$$1$$$ to $$$n$$$. All houses on the northern side and all houses on the southern side must lie along straight lines parallel to Heartfall River.There will be $$$m$$$ bridges, with the $$$i$$$-th bridge connecting house $$$u_i$$$ and house $$$v_i$$$ ($$$u_i \ne v_i$$$). It is guaranteed that all $$$n$$$ houses are connected by these bridges, that is, you can travel from any house to any other by crossing bridges. Also, there are no two bridges connecting the same pair of houses.Root wants to know how many ways there are to arrange the $$$n$$$ houses along the river, modulo $$$10^9+7$$$, such that the following conditions hold for the planned $$$m$$$ bridges:  For every bridge, the two houses it connects lie on opposite sides of the river;  The bridges do not cross when drawn as straight lines between the houses.   A possible arrangement of the houses when $$$n=5$$$. Two arrangements are considered different if at least one of the following conditions holds:  There exists a house that lies on a different side in each arrangement;  There exist two houses $$$a$$$ and $$$b$$$ that are on the same side in both arrangements, but $$$a$$$ comes before $$$b$$$ in one arrangement and $$$b$$$ comes before $$$a$$$ in the other. Since Root is distracted by his ex, whom destiny separated from him, he asks you to calculate the number of ways to arrange the houses along the river, modulo $$$10^9+7$$$.

## Input

Each test contains multiple test cases. The first line contains the number of test cases $$$t$$$ ($$$1 \le t \le 10^4$$$). The description of the test cases follows. The first line of each test case contains two integers $$$n$$$ and $$$m$$$ ($$$2 \leq n \leq 2 \cdot 10^5$$$, $$$n-1 \leq m \leq \min\left(\frac{n(n-1)}{2}, 2 \cdot 10^5\right)$$$) — the number of houses and the number of bridges.Then $$$m$$$ lines follow, the $$$i$$$-th line containing two integers $$$u_i$$$ and $$$v_i$$$ ($$$1 \leq u_i,v_i \leq n$$$, $$$u_i\ne v_i$$$) — the two houses that the $$$i$$$-th bridge connects.It is guaranteed that all the $$$n$$$ houses are connected by the bridges, and there are no two bridges connecting the same pair of houses.It is guaranteed that the sum of $$$n$$$ over all test cases does not exceed $$$2 \cdot 10^5$$$, and the sum of $$$m$$$ over all test cases does not exceed $$$2 \cdot 10^5$$$.

## Output

For each test case, output a single integer — the number of ways to arrange the $$$n$$$ houses along the river, modulo $$$10^9+7$$$.

## Example

### Input
```
42 11 23 31 21 32 35 41 21 33 43 54 31 21 31 4
```

### Output
```
2
0
8
12
```

## Note

In the first test case, either house $$$1$$$ should be built on the northern side and house $$$2$$$ on the southern side, or vice versa.In the second test case, at least two houses must be built on the same side of the river. But every pair of houses is connected by a bridge. So in every arrangement, at least one bridge will not cross the river. Thus, the answer is $$$0$$$.In the third test case, one of the possible arrangements of the houses is provided in the problem statement.