# MISSINGNUM7

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Missing Number

Chef had $4$ pieces of paper with him, one paper with $1$ written on it, one paper with $2$, one paper with $3$ and finally one paper with $4$.

Now, Chef lost one of the pieces of paper, and noticed that the other numbers on his papers add up to $S$. Find the number on the missing paper.

### Input Format
- The first and only line of input contains a single integer $S$.
### Output Format

Output the number on the missing paper.

### Constraints
- $6 \le S \le 9$
### Sample 1:
Input
Output

```
6

```

```
4

```

### Explanation:

Chef has the papers $1$, $2$ and $3$ with him; as they add up to $6$, so the missing has to be $4$.

### Sample 2:
Input
Output

```
9

```

```
1

```

## Solution

**Language:** Python  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-09-02T14:34:25.574Z  

```py
import sys


def solve(it) -> str:
    # write code here
    n = int(next(it))
    return str(10 - n)

def main():
    input_data = sys.stdin.read().split()
    it = iter(input_data)

    t = 1
    # t = int(next(it)) # comment it when no test case given

    answer: list[str] = []
    for _ in range(t):
        answer.append(solve(it))

    sys.stdout.write("".join(answer) + "\n")


if __name__ == "__main__":
    main()
```

---

[View on CodeChef](https://www.codechef.com/problems/MISSINGNUM7)