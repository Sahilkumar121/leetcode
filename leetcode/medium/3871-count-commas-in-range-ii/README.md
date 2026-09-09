# Count Commas in Range II

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given an integer `n`.

Return the  **total**  number of commas used when writing all integers from `[1, n]` (inclusive) in  **standard**  number formatting.

In  **standard**  formatting:

- A comma is inserted after every three digits from the right.
- Numbers with fewer than 4 digits contain no commas.

 

 **Example 1:** 

 **Input:**  n = 1002

 **Output:**  3

 **Explanation:** 

The numbers `"1,000"`, `"1,001"`, and `"1,002"` each contain one comma, giving a total of 3.

 **Example 2:** 

 **Input:**  n = 998

 **Output:**  0

 **Explanation:** 

 **​​​​​​​** All numbers from 1 to 998 have fewer than four digits. Therefore, no commas are used.

 

 **Constraints:** 

- 1 <= n <= 1015

## Solution

**Language:** Python  
**Runtime:** 4 ms (beats 3.40%)  
**Memory:** 19.2 MB (beats 51.70%)  
**Submitted:** 2026-09-09T14:43:59.250Z  

```py
class Solution:
    def countCommas(self, n: int) -> int:
        lower = 1000
        comma = 1
        result = 0

        while lower <= n:
            upper = lower * 1000 - 1
            upper = min(upper, n)

            count_number = (upper - lower) + 1
            result += count_number * comma

            lower *= 1000
            comma += 1

        return result
```

---

[View on LeetCode](https://leetcode.com/problems/count-commas-in-range-ii/)