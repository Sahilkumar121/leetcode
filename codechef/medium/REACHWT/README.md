# REACHWT

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Reach Weight

You need to buy some weights that total to exactly $N$ kg.

You can buy either $1$ kg weights for $20$ rupees, or $2$ kg weights for $30$ rupees.

Find the minimum cost to buy such a set of weights that sum to $N$ kg.

### Input Format
- The first line of input will contain a single integer $T$, denoting the number of test cases.
- The first and only line contains a single integer $N$.
### Output Format

For each test case, output on a new line the minimum total cost of buying a set of weights that total to exactly $N$ kg.

### Constraints
- $1 \le T \le 100$
- $1 \le N \le 100$
### Sample 1:
Input
Output

```
3
1
2
3

```

```
20
30
50

```

### Explanation:

 **Test Case 1:**  You buy $1$ one-kg weight for a cost of $20$.

 **Test Case 2:**  You buy $1$ two-kg weight for a cost of $30$.

## Solution

**Language:** Python  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-09-02T14:42:47.730Z  

```py
import sys


def solve(it) -> str:
    # write code here
    n = int(next(it))

    one_kg = n * 20
    two_kg = ((n // 2) * 30) + ((n % 2) * 20)

    return str(min(one_kg, two_kg))

def main():
    input_data = sys.stdin.read().split()
    it = iter(input_data)

    # t = 1
    t = int(next(it)) # comment it when no test case given

    answer: list[str] = []
    for _ in range(t):
        answer.append(solve(it))

    sys.stdout.write("\n".join(answer) + "\n")


if __name__ == "__main__":
    main()
```

---

[View on CodeChef](https://www.codechef.com/problems/REACHWT)