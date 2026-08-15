# Number of Provinces

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

There are `n` cities. Some of them are connected, while some are not. If city `a` is connected directly with city `b`, and city `b` is connected directly with city `c`, then city `a` is connected indirectly with city `c`.

A  **province**  is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an `n x n` matrix `isConnected` where `isConnected[i][j] = 1` if the `ith` city and the `jth` city are directly connected, and `isConnected[i][j] = 0` otherwise.

Return  *the total number of  **provinces***.

 

 **Example 1:** 

```
Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2

```

 **Example 2:** 

```
Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3

```

 

 **Constraints:** 

- 1 <= n <= 200
- n == isConnected.length
- n == isConnected[i].length
- isConnected[i][j] is 1 or 0.
- isConnected[i][i] == 1
- isConnected[i][j] == isConnected[j][i]

## Solution

**Language:** C++  
**Runtime:** 6 ms (beats 13.42%)  
**Memory:** 21.7 MB (beats 5.29%)  
**Submitted:** 2026-08-15T05:06:12.428Z  

```cpp
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {

        int V = isConnected.size();
        vector<bool> visited(V, false);

        int count = 0;

        for (int i = 0; i < V; i++) {
            queue<int> q;
            if (!visited[i]) {
                q.push(i);

                while (!q.empty()) {
                    int element = q.front();
                    q.pop();
                    visited[element] = true;

                    for (int j = 0; j < V; j++) {
                        if (isConnected[element][j] == 1 && !visited[j]) {
                            q.push(j);
                        }
                    }
                }

                count++;
            }
        }

        return count;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/number-of-provinces/)