# B. Tournament

**Time limit:** 2 seconds
**Memory limit:** 256 megabytes
**Input:** standard input
**Output:** standard output

## Problem Statement

You are given an array of integers $$$a_1,a_2,\dots,a_n$$$. A tournament is held with $$$n$$$ players. Player $$$i$$$ has strength $$$a_i$$$.While more than $$$k$$$ players remain,   Two remaining players are chosen at random;  Then the chosen player with the lower strength is eliminated. If the chosen players have the same strength, one is eliminated at random. Given integers $$$j$$$ and $$$k$$$ ($$$1 \leq j,k \leq n$$$), determine if there is any way for player $$$j$$$ to be one of the last $$$k$$$ remaining players.

## Input

The first line contains an integer $$$t$$$ ($$$1 \leq t \leq 10^4$$$)  — the number of test cases.The first line of each test case contains three integers $$$n$$$, $$$j$$$, and $$$k$$$ ($$$2\leq n \leq 2\cdot 10^5$$$, $$$1\leq j, k\leq n$$$).The second line of each test case contains $$$n$$$ integers, $$$a_1,a_2,\dots,a_n$$$ ($$$1\leq a_i\leq n$$$).It is guaranteed that the sum of $$$n$$$ over all test cases does not exceed $$$2\cdot 10^5$$$.

## Output

For each test case, output on a single line "YES" if player $$$j$$$ can be one of the last $$$k$$$ remaining players, and "NO" otherwise. You can output the answer in any case (upper or lower). For example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as positive responses.

## Example

### Input
```
35 2 33 2 4 4 15 4 15 3 4 5 26 1 11 2 3 4 5 6
```

### Output
```
YES
YES
NO
```

## Note

In the first sample, suppose that players $$$2$$$ and $$$5$$$ are chosen. Then player $$$2$$$ defeats player $$$5$$$. Now, the remaining player strengths are 3244 Next, suppose that players $$$3$$$ and $$$4$$$ are chosen. Then player $$$3$$$ might defeat player $$$4$$$. Now, the remaining player strengths are 324 Player $$$2$$$ is one of the last three players remaining.In the third sample, it can be shown that there is no way for player $$$1$$$ to be the last player remaining.