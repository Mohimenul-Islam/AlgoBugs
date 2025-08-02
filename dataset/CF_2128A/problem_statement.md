# A. Recycling Center

**Time limit:** 1 second
**Memory limit:** 256 megabytes
**Input:** standard input
**Output:** standard output

## Problem Statement

In the recycling center, there are $$$n$$$ trash bags, the $$$i$$$-th bag has a weight of $$$a_i$$$. At each second, two actions will happen successively:   First, you must choose a trash bag and destroy it. It will cost $$$1$$$ coin if the weight of the trash bag is strictly greater than $$$c$$$, and it will cost $$$0$$$ coins otherwise.  Then, the weight of each remaining trash bag will get multiplied by two.  What is the minimum number of coins you have to spend to get rid of all trash bags?

## Input

Each test contains multiple test cases. The first line contains the number of test cases $$$t$$$ ($$$1 \le t \le 1000$$$). The description of the test cases follows. The first line of each test case contains two integers $$$n$$$ and $$$c$$$ ($$$1 \leq n \leq 30$$$, $$$1 \leq c \leq 10^9)$$$.The second line of each test case contains $$$n$$$ integers $$$a_1, a_2, \ldots, a_n$$$ ($$$1 \leq a_i \leq 10^9$$$) — the weight of each trash bag.

## Output

For each test case, you must output a single integer — the minimum number of coins you have to spend to destroy all trash bags.

## Example

### Input
```
45 1010 4 15 1 83 421000000000 1000000000 100000000010 3029 25 2 12 15 42 14 6 16 910 10000001 1 1 1 1 1 1 1 1 864026633
```

### Output
```
2
3
6
1
```

## Note

In the following explanation:   Numbers in blue represent trash bags that have been destroyed for free,  Numbers in red represent trash bags that have been destroyed for $$$1$$$ coin,  Numbers in black represent trash bags that have not been destroyed yet. In the first test case, one solution is:   $$$[10, 4, 15, 1, 8]$$$  $$$[\color{blue}{10}, 8, 30, 2, 16]$$$, $$$10$$$ is destroyed for free because $$$10 \leq 10$$$.  $$$[\color{blue}{10}, \color{blue}{8}, 60, 4, 32]$$$, $$$8$$$ is destroyed for free because $$$8 \leq 10$$$.  $$$[\color{blue}{10}, \color{blue}{8}, 120, 8, \color{red}{32}]$$$, $$$32$$$ is destroyed for $$$1$$$ coin because $$$32 > 10$$$.  $$$[\color{blue}{10}, \color{blue}{8}, 240, \color{blue}{8}, \color{red}{32}]$$$, $$$8$$$ is destroyed for free because $$$8 \leq 10$$$.  $$$[\color{blue}{10}, \color{blue}{8}, \color{red}{240}, \color{blue}{8}, \color{red}{32}]$$$, $$$240$$$ is destroyed for $$$1$$$ coin because $$$240 > 10$$$. In total, you paid $$$2$$$ coins, and we can prove it is optimal.In the second test case, one solution is:   $$$[1\,000\,000\,000, 1\,000\,000\,000, 1\,000\,000\,000]$$$  $$$[\color{red}{1\,000\,000\,000}, 2\,000\,000\,000, 2\,000\,000\,000]$$$, $$$1\,000\,000\,000$$$ is destroyed for $$$1$$$ coin because $$$1\,000\,000\,000 > 42$$$.  $$$[\color{red}{1\,000\,000\,000}, \color{red}{2\,000\,000\,000}, 4\,000\,000\,000]$$$, $$$2\,000\,000\,000$$$ is destroyed for $$$1$$$ coin because $$$2\,000\,000\,000 > 42$$$.  $$$[\color{red}{1\,000\,000\,000}, \color{red}{2\,000\,000\,000}, \color{red}{4\,000\,000\,000}]$$$, $$$4\,000\,000\,000$$$ is destroyed for $$$1$$$ coin because $$$4\,000\,000\,000 > 42$$$.