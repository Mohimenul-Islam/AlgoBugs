# E. Game with Binary String

**Time limit:** 3 seconds
**Memory limit:** 512 megabytes
**Input:** standard input
**Output:** standard output

## Problem Statement

Consider the following game. Two players have a binary string (a string consisting of characters 0 and/or 1). The players take turns, the first player makes the first turn. During a player's turn, he or she has to choose exactly two adjacent elements of the string and remove them (the first element and the last element are also considered adjacent). Furthermore, there are additional constraints depending on who makes the move:  if it's the first player's move, both chosen characters should be 0;  if it's the second player's move, at least one of the chosen characters should be 1. The player who can't make a valid move loses the game. This also means that if the string currently has less than $$$2$$$ characters, the current player loses the game.You are given a binary string $$$s$$$ of length $$$n$$$. You have to calculate the number of its substrings such that, if the game is played on that substring and both players make optimal decisions, the first player wins. In other words, calculate the number of pairs $$$(l, r)$$$ such that $$$1 \le l \le r \le n$$$ and the first player has a winning strategy on the string $$$s_l s_{l+1} \dots s_r$$$.

## Input

The first line contains one integer $$$n$$$ ($$$1 \le n \le 3 \cdot 10^5$$$).The second line contains the string $$$s$$$, consisting of exactly $$$n$$$ characters. Each character of the string is either 0 or 1.

## Output

Print one integer — the number of substrings such that, if the game is played on that substring, the first player wins.

## Example

### Input
```
100010010011
```

### Output
```
12
```

## Note

In the first example, the following substrings are winning for the first player ($$$s[l:r]$$$ denotes $$$s_l s_{l+1} \dots s_r$$$):  $$$s[1:2]$$$;  $$$s[1:3]$$$;  $$$s[1:7]$$$;  $$$s[2:4]$$$;  $$$s[2:8]$$$;  $$$s[3:5]$$$;  $$$s[4:5]$$$;  $$$s[4:6]$$$;  $$$s[5:7]$$$;  $$$s[6:8]$$$;  $$$s[7:8]$$$;  $$$s[7:9]$$$.