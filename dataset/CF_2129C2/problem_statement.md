# C2. Interactive RBS (Medium Version)

**Time limit:** 2 seconds
**Memory limit:** 256 megabytes
**Input:** standard input
**Output:** standard output

## Problem Statement

This is an interactive problem.This is the medium version of the problem. The only difference is the limit on the number of queries. You can make hacks only if all versions of the problem are solved.There is a hidden bracket sequence $$$s$$$ of length $$$n$$$, where $$$s$$$ only contains $$$\texttt{'('}$$$ and $$$\texttt{')'}$$$. It is guaranteed that $$$s$$$ contains at least one $$$\texttt{'('}$$$ and one $$$\texttt{')'}$$$.To find this bracket sequence, you can ask queries. Each query has the following form: you pick an integer $$$k$$$ and arbitrary indices $$$i_1, i_2, \ldots, i_k$$$ ($$$1 \le k \le 1000$$$, $$$1 \le i_1, i_2, \ldots, i_k \le n$$$). Note that the indices can be equal. Next, you receive an integer $$$f(s_{i_1}s_{i_2}\ldots s_{i_k})$$$ calculated by the jury.For a bracket sequence $$$t$$$, $$$f(t)$$$ is the number of non-empty regular bracket substrings in $$$t$$$ (the substrings must be contiguous). For example, $$$f(\texttt{"()())"}) = 3$$$.A bracket sequence is called regular if it can be constructed in the following way.   The empty sequence $$$\varnothing$$$ is regular.  If the bracket sequence $$$A$$$ is regular, then $$$\mathtt{(}A\mathtt{)}$$$ is also regular.  If the bracket sequences $$$A$$$ and $$$B$$$ are regular, then the concatenated sequence $$$A B$$$ is also regular. For example, the sequences $$$\texttt{"(())()"}$$$, $$$\texttt{"()"}$$$ are regular, while $$$\texttt{"(()"}$$$ and $$$\texttt{"())("}$$$ are not.Find the sequence $$$s$$$ using no more than $$$200$$$ queries.

## Input

Each test contains multiple test cases. The first line contains the number of test cases $$$t$$$ ($$$1 \le t \le 20$$$). The description of the test cases follows.

## Example

### Input
```
2
3

0

1

1

2

3
```

### Output
```
? 4 1 2 3 3

? 2 2 1

? 2 3 1

! )((

? 4 1 2 1 2

! ()
```

## Note

In the first test case, the hidden bracket sequence is $$$s=\texttt{")(("}$$$.For the query "? 4 1 2 3 3", the jury returns $$$0$$$ because $$$f(s_{1}s_{2}s_{3}s_{3}) = f(\texttt{")((("}) = 0$$$.For the query "? 2 2 1", the jury returns $$$1$$$ because $$$f(s_{2}s_{1}) = f(\texttt{"()"}) = 1$$$.For the query "? 2 3 1", the jury returns $$$1$$$ because $$$f(s_{3}s_{1}) = f(\texttt{"()"}) = 1$$$.In the second test case, the hidden bracket sequence is $$$s=\texttt{"()"}$$$.For the query "? 4 1 2 1 2", the jury returns $$$3$$$ because $$$f(s_{1}s_{2}s_{1}s_{2}) = f(\texttt{"()()"}) = 3$$$.Note that the example is only for understanding the statement and does not guarantee finding the unique bracket sequence $$$s$$$.