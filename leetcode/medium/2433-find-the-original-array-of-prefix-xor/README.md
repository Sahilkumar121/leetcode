# Find The Original Array of Prefix Xor

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given an  **integer**  array `pref` of size `n`. Find and return  *the array* `arr` *of size* `n` *that satisfies* :

- pref[i] = arr[0] ^ arr[1] ^... ^ arr[i].

Note that `^` denotes the  **bitwise-xor**  operation.

It can be proven that the answer is  **unique**.

 

 **Example 1:** 

```
Input: pref = [5,2,0,3,1]
Output: [5,7,2,3,2]
Explanation: From the array [5,7,2,3,2] we have the following:
- pref[0] = 5.
- pref[1] = 5 ^ 7 = 2.
- pref[2] = 5 ^ 7 ^ 2 = 0.
- pref[3] = 5 ^ 7 ^ 2 ^ 3 = 3.
- pref[4] = 5 ^ 7 ^ 2 ^ 3 ^ 2 = 1.

```

 **Example 2:** 

```
Input: pref = [13]
Output: [13]
Explanation: We have pref[0] = arr[0] = 13.

```

 

 **Constraints:** 

- 1 <= pref.length <= 105
- 0 <= pref[i] <= 106

## Solution

**Language:** Python  
**Runtime:** 28 ms (beats 53.82%)  
**Memory:** 37 MB (beats 31.87%)  
**Submitted:** 2026-09-08T16:15:37.269Z  

```py
class Solution:
    def findArray(self, pref: List[int]) -> List[int]:
        n = len(pref)

        ans: list[int] = [0] * n
        ans[0] = pref[0]

        for i in range(1, n):
            ans[i] = pref[i - 1] ^ pref[i]

        return ans
```

---

[View on LeetCode](https://leetcode.com/problems/find-the-original-array-of-prefix-xor/)