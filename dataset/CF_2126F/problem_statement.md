# F. 1-1-1, Free Tree!

**Time limit:** 4 seconds
**Memory limit:** 256 megabytes
**Input:** standard input
**Output:** standard output

## Problem Statement

Given a tree$$$^{\text{∗}}$$$ with $$$n$$$ vertices numbered from $$$1$$$ to $$$n$$$. Each vertex has an initial color $$$a_i$$$.Each edge of the tree is defined by three numbers: $$$u_i$$$, $$$v_i$$$, and $$$c_i$$$, where $$$u_i$$$ and $$$v_i$$$ are the endpoints of the edge, and $$$c_i$$$ is the edge parameter. The cost of the edge is defined as follows: if the colors of vertices $$$u_i$$$ and $$$v_i$$$ are the same, the cost is $$$0$$$; otherwise, the cost is $$$c_i$$$.You are also given $$$q$$$ queries. Each query has the form: repaint vertex $$$v$$$ to color $$$x$$$. The queries depend on each other (after each query, the color change is preserved). After each query, you need to output the sum of the costs of all edges in the tree.$$$^{\text{∗}}$$$A tree is a connected graph without cycles.

## Input

The first line contains an integer $$$t$$$ ($$$1 \le t \le 10^4$$$) — the number of test cases.The first line of each test case contains two integers $$$n$$$ and $$$q$$$ ($$$1 \le n, q \le 2\cdot10^5$$$) — the number of vertices and the number of queries, respectively.The second line contains $$$n$$$ integers $$$a_1, a_2, \dots, a_n$$$ ($$$1 \le a_i \le n$$$), where the $$$i$$$-th number specifies the initial color of vertex $$$i$$$.The next $$$n-1$$$ lines describe the edges of the tree. Each line contains three integers $$$u$$$, $$$v$$$, and $$$c$$$, denoting an edge between vertices $$$u$$$ and $$$v$$$ with parameter $$$c$$$ ($$$1 \le u, v \le n$$$, $$$1 \le c \le 10^9$$$).The following $$$q$$$ lines contain the queries. Each query contains two integers $$$v$$$ and $$$x$$$ — repaint vertex $$$v$$$ to color $$$x$$$ ($$$1 \le v,x \le n$$$).It is guaranteed that the sum of $$$n$$$ and the sum of $$$q$$$ across all test cases do not exceed $$$2\cdot10^5$$$.

## Output

For each query, output a single integer on a separate line — the sum of the costs of all edges in the tree after applying the corresponding query.

## Example

### Input
```
41 111 12 31 11 2 101 22 21 15 41 2 1 2 31 2 52 3 32 4 44 5 73 25 21 22 34 31 1 2 21 2 22 3 62 4 83 14 12 2
```

### Output
```
0
10
0
10
12
5
0
12
8
0
16
```

## Note

First test: $$$n =1$$$, one vertex — no edges. Query: repaint $$$a_1$$$ to $$$1$$$, the sum of costs is $$$0$$$.Second test: $$$n=2$$$, edge $$$1 - 2$$$ ($$$c=10$$$). Queries:  $$$a_1 = 2$$$: colors [$$$2, 1$$$], cost is $$$10$$$;  $$$a_2 = 2$$$: colors [$$$2, 2$$$], cost $$$0$$$;  $$$a_1 = 1$$$: colors [$$$1, 2$$$], cost $$$10$$$. Third test: $$$n=5$$$, edges: $$$1 - 2\ (c=5)$$$, $$$2 - 3\ (c=3)$$$, $$$2 - 4\ (c=4)$$$, $$$4 - 5\ (c=7)$$$. Initial colors $$$[1,2,1,2,3]$$$. Queries:$$$a_3 = 2 \rightarrow [1,2,2,2,3]$$$: edges $$$1 - 2\ (c = 5)$$$ and $$$4 - 5\ (c=7)$$$ give $$$12$$$;$$$a_5 = 2 \rightarrow [1,2,2,2,2]$$$: edge $$$1 - 2\ (c=5)$$$, cost $$$5$$$;$$$a_1 = 2 \rightarrow [2,2,2,2,2]$$$: cost is $$$0$$$;$$$a_2 = 3 \rightarrow [2,3,2,2,2]$$$: edges $$$1-2\ (5)$$$, $$$2-3\ (3)$$$, $$$2-4\ (4)$$$ give $$$12$$$.