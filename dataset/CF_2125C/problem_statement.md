# C. Count Good Numbers

**Time limit:** 2 seconds
**Memory limit:** 512 megabytes
**Input:** standard input
**Output:** standard output

## Problem Statement

A prime number is a positive integer that has exactly two divisors: $$$1$$$ and itself. The first several prime numbers are $$$2, 3, 5, 7, 11, \dots$$$.Prime factorization of a positive integer is representing it as a product of prime numbers. For example:  the prime factorization of $$$111$$$ is $$$3 \cdot 37$$$;  the prime factorization of $$$43$$$ is $$$43$$$;  the prime factorization of $$$12$$$ is $$$2 \cdot 2 \cdot 3$$$. For every positive integer, its prime factorization is unique (if you don't consider the order of primes in the product).We call a positive integer good if all primes in its factorization consist of at least two digits. For example:  $$$343 = 7 \cdot 7 \cdot 7$$$ is not good;  $$$111 = 3 \cdot 37$$$ is not good;  $$$1111 = 11 \cdot 101$$$ is good;  $$$43 = 43$$$ is good. You have to calculate the number of good integers from $$$l$$$ to $$$r$$$ (endpoints included).

## Input

The first line contains one integer $$$t$$$ ($$$1 \le t \le 10^3$$$) — the number of test cases.Each test case consists of one line containing two integers $$$l$$$ and $$$r$$$ ($$$2 \le l \le r \le 10^{18}$$$).

## Output

For each test case, print one integer — the number of good integers from $$$l$$$ to $$$r$$$.

## Example

### Input
```
42 1002 100013 372 1000000000000000000
```

### Output
```
21
227
7
228571428571428570
```