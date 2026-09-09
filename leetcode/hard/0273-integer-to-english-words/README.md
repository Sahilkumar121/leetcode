# Integer to English Words

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

Convert a non-negative integer `num` to its English words representation.

 

 **Example 1:** 

```
Input: num = 123
Output: "One Hundred Twenty Three"

```

 **Example 2:** 

```
Input: num = 12345
Output: "Twelve Thousand Three Hundred Forty Five"

```

 **Example 3:** 

```
Input: num = 1234567
Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"

```

 

 **Constraints:** 

- 0 <= num <= 231 - 1

## Solution

**Language:** Python  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 20.5 MB (beats 7.53%)  
**Submitted:** 2026-09-09T18:10:48.307Z  

```py
class Solution:
    def numberToWords(self, num: int) -> str:
        if num == 0:
            return "Zero"


        self.belowTen = {
            0: "",
            1: "One",
            2: "Two",
            3: "Three",
            4: "Four",
            5: "Five",
            6: "Six",
            7: "Seven",
            8: "Eight",
            9: "Nine",
        }
        self.belowTwenty = {
            10: "Ten",
            11: "Eleven",
            12: "Twelve",
            13: "Thirteen",
            14: "Fourteen",
            15: "Fifteen",
            16: "Sixteen",
            17: "Seventeen",
            18: "Eighteen",
            19: "Nineteen",
        }
        self.belowHundred = {
            2: "Twenty",
            3: "Thirty",
            4: "Forty",
            5: "Fifty",
            6: "Sixty",
            7: "Seventy",
            8: "Eighty",
            9: "Ninety",
        }

        def findWord(num: int):
            if num < 10:
                return self.belowTen[num]

            if num < 20:
                return self.belowTwenty[num]

            if num < 100:
                return self.belowHundred[num // 10] + (
                    " " + findWord(num % 10) if num % 10 != 0 else ""
                )

            if num < 1000:
                return (
                    findWord(num // 100)
                    + " Hundred"
                    + (" " + findWord(num % 100) if num % 100 != 0 else "")
                )

            if num < 1000000:
                return (
                    findWord(num // 1000)
                    + " Thousand"
                    + (" " + findWord(num % 1000) if num % 1000 != 0 else "")
                )

            if num < 1000000000:
                return (
                    findWord(num // 1000000)
                    + " Million"
                    + (" " + findWord(num % 1000000) if num % 1000000 != 0 else "")
                )

            else:
                return (
                    findWord(num // 1000000000)
                    + " Billion"
                    + (
                        " " + findWord(num % 1000000000)
                        if num % 1000000000 != 0
                        else ""
                    )
                )

        return findWord(num)
```

---

[View on LeetCode](https://leetcode.com/problems/integer-to-english-words/)