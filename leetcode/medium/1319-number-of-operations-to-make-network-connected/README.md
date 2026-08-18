# Number of Operations to Make Network Connected

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

There are `n` computers numbered from `0` to `n - 1` connected by ethernet cables `connections` forming a network where `connections[i] = [ai, bi]` represents a connection between computers `ai` and `bi`. Any computer can reach any other computer directly or indirectly through the network.

You are given an initial computer network `connections`. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected.

Return  *the minimum number of times you need to do this in order to make all the computers connected*. If it is not possible, return `-1`.

 

 **Example 1:** 

```
Input: n = 4, connections = [[0,1],[0,2],[1,2]]
Output: 1
Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3.

```

 **Example 2:** 

```
Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
Output: 2

```

 **Example 3:** 

```
Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2]]
Output: -1
Explanation: There are not enough cables.

```

 

 **Constraints:** 

- 1 <= n <= 105
- 1 <= connections.length <= min(n * (n - 1) / 2, 105)
- connections[i].length == 2
- 0 <= ai, bi < n
- ai != bi
- There are no repeated connections.
- No two computers are connected by more than one cable.

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 42.2 MB (beats 71.32%)  
**Submitted:** 2026-08-18T06:34:44.875Z  

```cpp
class Solution {
public:
    int find(int i, vector<int>& parent) {
        if (parent[i] == i) {
            return i;
        }

        return parent[i] = find(parent[i], parent);
    }

    void union_find(int x, int y, vector<int>& parent, vector<int>& rank) {
        int x_parent = find(x, parent);
        int y_parent = find(y, parent);

        if (x_parent != y_parent) {
            if (rank[x_parent] > rank[y_parent]) {
                parent[y_parent] = x_parent;
            } else if (rank[x_parent] < rank[y_parent]) {
                parent[x_parent] = y_parent;
            } else {
                parent[y_parent] = x_parent;
                rank[x_parent]++;
            }
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) {
            return -1;
        }

        vector<int> parent(n);
        vector<int> rank(n, 0);

        for (size_t i = 0; i < n; ++i) {
            parent[i] = i;
        }

        // create union connection of all computers
        for (const auto& pairs : connections) {
            union_find(pairs.front(), pairs.back(), parent, rank);
        }

        int extra_wire = 0;

        for (size_t i = 0; i < n; ++i) {
            if (parent[i] == i) {
                extra_wire++;
            }
        }

        return extra_wire - 1;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/number-of-operations-to-make-network-connected/)