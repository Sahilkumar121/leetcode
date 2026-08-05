# FINELE

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Final Element

You are given an array $A$ of $N$ non-negative integers.

Define a process as follows:

- Create a new array $B$ of length $N - 1$ such that $B_i = A_i \oplus A_{i + 1}$, where $\oplus$ represents the Bitwise XOR operator.
- Replace $A$ with $B$.

If we perform the process $N - 1$ times iteratively, we are left with an array of length $1$. Find the last element.

### Input Format
- The first line of input will contain a single integer $T$, denoting the number of test cases.
- Each test case consists of multiple lines of input. The first line contains $1$ integer $N$ - the size of the array. The second line contains $N$ integers $A_1, A_2, \ldots, A_N$.
### Output Format

For each test case, output on a new line the final element after applying the process $N - 1$ times.

### Constraints
- $1 \le T \le 10^4$
- $2 \le N \le 2 \cdot 10^5$
- $0 \le A_i \lt 2^{30}$
- The sum of $N$ over all test cases does not exceed $2 \cdot 10^5$.
### Sample 1:
Input
Output

```
3
3
2 3 5
4
1 1 1 1
4
1 2 3 4

```

```
7
0
4
```

### Explanation:

 **Test Case 1**  : First $A$ changes to $[2 \oplus 3, 3 \oplus 5] = [1, 6]$. Finally, it changes to $[1 \oplus 6] = [7]$.

## Solution

**Language:** Python  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-08-05T08:42:19.321Z  

```py
print("Hello, world!")

```

---

[View on CodeChef](https://www.codechef.com/problems/FINELE)