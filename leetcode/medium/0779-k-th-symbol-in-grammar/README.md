# K-th Symbol in Grammar

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

We build a table of `n` rows (**1-indexed**). We start by writing `0` in the `1st` row. Now in every subsequent row, we look at the previous row and replace each occurrence of `0` with `01`, and each occurrence of `1` with `10`.

- For example, for n = 3, the 1st row is 0, the 2nd row is 01, and the 3rd row is 0110.

Given two integer `n` and `k`, return the `kth` (**1-indexed**) symbol in the `nth` row of a table of `n` rows.

 

 **Example 1:** 

```
Input: n = 1, k = 1
Output: 0
Explanation: row 1: 0

```

 **Example 2:** 

```
Input: n = 2, k = 1
Output: 0
Explanation: 
row 1: 0
row 2: 01

```

 **Example 3:** 

```
Input: n = 2, k = 2
Output: 1
Explanation: 
row 1: 0
row 2: 01

```

 

 **Constraints:** 

- 1 <= n <= 30
- 1 <= k <= 2n - 1

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 8 MB (beats 11.17%)  
**Submitted:** 2026-09-01T06:07:40.525Z  

```cpp
class Solution {
public:
    int kthGrammar(int n, int k) {

        if (n == 1 && k == 1) {
            return 0;
        }

        int length = pow(2, n - 1);
        int mid = length / 2;

        if (k <= mid) {
            return kthGrammar(n - 1, k);
        } else {
            return !kthGrammar(n - 1, k - mid);
        }
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/k-th-symbol-in-grammar/)