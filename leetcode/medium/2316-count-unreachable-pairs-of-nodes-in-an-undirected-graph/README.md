# Count Unreachable Pairs of Nodes in an Undirected Graph

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given an integer `n`. There is an  **undirected**  graph with `n` nodes, numbered from `0` to `n - 1`. You are given a 2D integer array `edges` where `edges[i] = [ai, bi]` denotes that there exists an  **undirected**  edge connecting nodes `ai` and `bi`.

Return  *the  **number of pairs**  of different nodes that are  **unreachable**  from each other*.

 

 **Example 1:** 

```
Input: n = 3, edges = [[0,1],[0,2],[1,2]]
Output: 0
Explanation: There are no pairs of nodes that are unreachable from each other. Therefore, we return 0.

```

 **Example 2:** 

```
Input: n = 7, edges = [[0,2],[0,5],[2,4],[1,6],[5,4]]
Output: 14
Explanation: There are 14 pairs of nodes that are unreachable from each other:
[[0,1],[0,3],[0,6],[1,2],[1,3],[1,4],[1,5],[2,3],[2,6],[3,4],[3,5],[3,6],[4,6],[5,6]].
Therefore, we return 14.

```

 

 **Constraints:** 

- 1 <= n <= 105
- 0 <= edges.length <= 2 * 105
- edges[i].length == 2
- 0 <= ai, bi < n
- ai != bi
- There are no repeated edges.

## Solution

**Language:** C++  
**Runtime:** 0 ms  
**Memory:** 8.5 MB  
**Submitted:** 2026-08-19T16:44:24.036Z  

```cpp
class Solution {
public:
    int find(int i, vector<int> &parent)
    {
        if (i == parent[i])
        {
            return i;
        }

        return parent[i] = find(parent[i], parent);
    }

    void union_find(int x, int y, vector<int> &parent, vector<int> &rank)
    {
        int x_parent = find(x, parent);
        int y_parent = find(y, parent);

        if (x_parent != y_parent)
        {
            if (rank[x_parent] > rank[y_parent])
            {
                parent[y_parent] = x_parent;
            }
            else if (rank[y_parent] > rank[x_parent])
            {
                parent[x_parent] = y_parent;
            }

            else
            {
                parent[y_parent] = x_parent;
                rank[x_parent]++;
            }
        }
    }

    long long countPairs(int n, vector<vector<int>> &edges)
    {

        vector<int> parent(n, -1);
        vector<int> rank(n, 0);
        for (int i = 0; i < n; ++i)
        {
            parent[i] = i;
        }

        // create union of edges
        for (const auto &pairs : edges)
        {
            union_find(pairs.front(), pairs.back(), parent, rank);
        }

        // find components
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            m[parent[i]]++;
        }

        int remaining = n;
        long long count = 0;

        for (const auto &pair : m)
        {
            count += pair.second * (remaining - pair.second);
            remaining -= pair.second;
        }

        return count;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/)