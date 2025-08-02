# B. Above the Clouds

**Time limit:** 2 seconds
**Memory limit:** 256 megabytes
**Input:** standard input
**Output:** standard output

## Problem Statement

You are given a string $$$s$$$ of length $$$n$$$, consisting of lowercase letters of the Latin alphabet. Determine whether there exist three non-empty strings $$$a$$$, $$$b$$$, and $$$c$$$ such that: $$$a + b + c = s$$$, meaning the concatenation$$$^{\text{∗}}$$$ of strings $$$a$$$, $$$b$$$, and $$$c$$$ equals $$$s$$$. The string $$$b$$$ is a substring$$$^{\text{†}}$$$ of the string $$$a + c$$$, which is the concatenation of strings $$$a$$$ and $$$c$$$. $$$^{\text{∗}}$$$Concatenation of strings $$$a$$$ and $$$b$$$ is defined as the string $$$a + b = a_1a_2 \ldots a_pb_1b_2 \ldots b_q$$$, where $$$p$$$ and $$$q$$$ are the lengths of strings $$$a$$$ and $$$b$$$, respectively. For example, the concatenation of the strings "code" and "forces" is "codeforces". $$$^{\text{†}}$$$A string $$$a$$$ is a substring of a string $$$b$$$ if $$$a$$$ can be obtained from $$$b$$$ by the deletion of several (possibly, zero or all) characters from the beginning and several (possibly, zero or all) characters from the end.

## Input

Each test consists of multiple test cases. The first line contains a single integer $$$t$$$ ($$$1 \leq t \leq 10^4$$$) — the number of test cases. The description of the test cases follows.The first line of each test case contains a single integer $$$n$$$ ($$$3 \leq n \leq 10^5$$$) — the length of the string $$$s$$$. The second line of each test case contains the string $$$s$$$ of length $$$n$$$, consisting of lowercase letters of the Latin alphabet. It is guaranteed that the sum of $$$n$$$ across all test cases does not exceed $$$2 \cdot 10^5$$$.

## Output

For each test case, output "Yes" if there exist three non-empty strings $$$a$$$, $$$b$$$, and $$$c$$$ that satisfy the conditions, and "No" otherwise. You may output the answer in any case (upper or lower). For example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as positive answers.

## Example

### Input
```
123aaa3aba3aab4abca4abba4aabb5abaca5abcda5abcba6abcbbf6abcdaa3abb
```

### Output
```
Yes
No
Yes
No
Yes
Yes
Yes
No
Yes
Yes
Yes
Yes
```

## Note

In the first test case, there exist unique non-empty strings $$$a$$$, $$$b$$$, and $$$c$$$ such that $$$a + b + c = s$$$. These are the strings $$$a =$$$ "a", $$$b =$$$ "a", and $$$c =$$$ "a". The concatenation of strings $$$a$$$ and $$$c$$$ equals $$$a + c = $$$ "aa". The string $$$b$$$ is a substring of this string. In the sixth test case, one can choose $$$a = $$$ "a", $$$b = $$$ "ab", and $$$c = $$$ "b". The concatenation of strings $$$a$$$ and $$$c$$$ equals $$$a + c = $$$ "ab". The string $$$b$$$ is a substring of this string. In the seventh test case, one can choose $$$a = $$$ "ab", $$$b = $$$ "a", and $$$c = $$$ "ca". The concatenation of strings $$$a$$$ and $$$c$$$ equals $$$a + c = $$$ "abca". The string $$$b$$$ is a substring of this string.