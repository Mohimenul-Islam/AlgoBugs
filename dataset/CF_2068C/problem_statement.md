# C. Ads

**Time limit:** 3 seconds
**Memory limit:** 1024 megabytes
**Input:** standard input
**Output:** standard output

## Problem Statement

You have $$$n$$$ videos on your watchlist on the popular platform YooCube. The $$$i$$$-th video lasts $$$d_i$$$ minutes.YooCube has recently increased the frequency of their ads. Ads are shown only between videos. After finishing a video, an ad is shown if either of these two conditions is true:   three videos have been watched since the last ad;  at least $$$k$$$ minutes have passed since the end of the last ad. You want to watch the $$$n$$$ videos in your watchlist. Given that you have just watched an ad, and that you can choose the order of the $$$n$$$ videos, what is the minimum number of ads that you are forced to watch? You can start a new video immediately after the previous video or ad ends, and you don't have to watch any ad after you finish.

## Input

Each test contains multiple test cases. The first line contains an integer $$$t$$$ ($$$1 \leq t \leq 100\,000$$$) — the number of test cases. The descriptions of the $$$t$$$ test cases follow.The first line of each test case contains two integers $$$n$$$ and $$$k$$$ ($$$1 \leq n \leq 100\,000, 1 \leq k \leq 30\,000$$$) — the number of videos in your watchlist and the parameter that determines when ads are shown.The second line contains $$$n$$$ integers $$$d_1, d_2, \ldots, d_n (1 \leq d_i \leq 10\,000)$$$ — the lengths of the videos.The sum of the values of $$$n$$$ over all test cases does not exceed $$$10^6$$$.

## Output

For each test case, print the minimum number of ads that you need to watch.

## Example

### Input
```
58 254 5 18 3 17 17 18 147 2120 14 1 4 20 8 48 120 5 9 4 14 12 2 208 372 13 13 11 12 19 16 184 3815 3 14 7
```

### Output
```
2
2
7
2
1
```

## Note

In the first test case, a possible viewing order is $$$4, 1, 8, 2, 5, 6, 7, 3$$$ (the corresponding lengths being $$$3, 4, 14, 5, 17, 17, 18, 18$$$). With this order, you will have to watch an ad after the first three videos and then another after the second three videos. Note that you don't have to watch an ad after you finish watching all your videos.