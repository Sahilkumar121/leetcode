# Satisfiability of Equality Equations

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given an array of strings `equations` that represent relationships between variables where each string `equations[i]` is of length `4` and takes one of two different forms: `"xi==yi"` or `"xi!=yi"`.Here, `xi` and `yi` are lowercase letters (not necessarily different) that represent one-letter variable names.

Return `true` *if it is possible to assign integers to variable names so as to satisfy all the given equations, or* `false` *otherwise*.

 

 **Example 1:** 

```
Input: equations = ["a==b","b!=a"]
Output: false
Explanation: If we assign say, a = 1 and b = 1, then the first equation is satisfied, but not the second.
There is no way to assign the variables to satisfy both equations.

```

 **Example 2:** 

```
Input: equations = ["b==a","a==b"]
Output: true
Explanation: We could assign a = 1 and b = 1 to satisfy both equations.

```

 

 **Constraints:** 

- 1 <= equations.length <= 500
- equations[i].length == 4
- equations[i][0] is a lowercase letter.
- equations[i][1] is either '=' or '!'.
- equations[i][2] is '='.
- equations[i][3] is a lowercase letter.

## Solution

**Language:** C++  
**Runtime:** 0 ms  
**Memory:** 8.3 MB  
**Submitted:** 2026-08-18T05:14:20.801Z  

```cpp
class Solution {
public:
    int find(int i, int parent[]) {
        if (parent[i] == i) {
            return i;
        }

        return parent[i] = find(parent[i], parent);
    }

    void union_find(int x, int y, int parent[], int rank[]) {
        int x_parent = find(x, parent);
        int y_parent = find(y, parent);

        if (x_parent != y_parent) {
            if (rank[x_parent] > rank[y_parent]) {
                parent[y_parent] = x_parent;
            } else if (rank[x_parent] < rank[y_parent]) {
                parent[x_parent] = y_parent;
            } else {
                parent[y_parent] = x_parent;
                x_parent++;
            }
        }
    }
    bool equationsPossible(vector<string>& equations) {

        int parent[26];
        int rank[26] = {0};

        for (int i = 0; i < 26; i++) {
            parent[i] = i;
        }

        for (const auto& equation : equations) {
            if (equation[1] == '=') {
                int x_position = equation[0] - 'a';
                int y_position = equation[3] - 'a';

                union_find(x_position, y_position, parent, rank);
            }
        }

        for (const auto& equation : equations) {
            if (equation[1] == '!') {
                int x_position = equation[0] - 'a';
                int y_position = equation[3] - 'a';

                if (x_position == y_position) {
                    return false;
                }
            }
        }

        return true;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/satisfiability-of-equality-equations/)