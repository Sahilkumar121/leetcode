# Find the Town Judge

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

In a town, there are `n` people labeled from `1` to `n`. There is a rumor that one of these people is secretly the town judge.

If the town judge exists, then:

- The town judge trusts nobody.
- Everybody (except for the town judge) trusts the town judge.
- There is exactly one person that satisfies properties 1 and 2.

You are given an array `trust` where `trust[i] = [ai, bi]` representing that the person labeled `ai` trusts the person labeled `bi`. If a trust relationship does not exist in `trust` array, then such a trust relationship does not exist.

Return  *the label of the town judge if the town judge exists and can be identified, or return* `-1` *otherwise*.

 

 **Example 1:** 

```
Input: n = 2, trust = [[1,2]]
Output: 2

```

 **Example 2:** 

```
Input: n = 3, trust = [[1,3],[2,3]]
Output: 3

```

 **Example 3:** 

```
Input: n = 3, trust = [[1,3],[2,3],[3,1]]
Output: -1

```

 

 **Constraints:** 

- 1 <= n <= 1000
- 0 <= trust.length <= 104
- trust[i].length == 2
- All the pairs of trust are unique.
- ai != bi
- 1 <= ai, bi <= n

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 65 MB (beats 83.91%)  
**Submitted:** 2026-08-26T05:07:25.137Z  

```cpp
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {

        if (n == 1) return 1;
        vector<int> trust_level(n + 1, 0);

        for (const auto& people : trust) {
            trust_level[people[0]]--;
            trust_level[people[1]]++;
        }

        for (int i = 0; i < n + 1; i++) {
            if (trust_level[i] > 0 && trust_level[i] == n - 1) {
                return i;
            }
        }

        return -1;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/find-the-town-judge/)