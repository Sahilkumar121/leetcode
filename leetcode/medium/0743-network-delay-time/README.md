# Network Delay Time

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given a network of `n` nodes, labeled from `1` to `n`. You are also given `times`, a list of travel times as directed edges `times[i] = (ui, vi, wi)`, where `ui` is the source node, `vi` is the target node, and `wi` is the time it takes for a signal to travel from source to target.

We will send a signal from a given node `k`. Return  *the  **minimum**  time it takes for all the*  `n`  *nodes to receive the signal*. If it is impossible for all the `n` nodes to receive the signal, return `-1`.

 

 **Example 1:** 

```
Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
Output: 2

```

 **Example 2:** 

```
Input: times = [[1,2,1]], n = 2, k = 1
Output: 1

```

 **Example 3:** 

```
Input: times = [[1,2,1]], n = 2, k = 2
Output: -1

```

 

 **Constraints:** 

- 1 <= k <= n <= 100
- 1 <= times.length <= 6000
- times[i].length == 3
- 1 <= ui, vi <= n
- ui != vi
- 0 <= wi <= 100
- All the pairs (ui, vi) are unique. (i.e., no multiple edges.)

## Solution

**Language:** C++  
**Runtime:** 86 ms (beats 46.00%)  
**Memory:** 44.7 MB (beats 43.39%)  
**Submitted:** 2026-08-21T03:50:47.651Z  

```cpp
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int, int>>> adj(n + 1, vector<pair<int, int>>());
        for (const auto& vertices : times) {
            adj[vertices[0]].push_back({vertices[1], vertices[2]});
        }

        set<pair<int, int>> s;
        s.insert({0, k});

        vector<int> result(n + 1, INT_MAX);
        result[k] = 0;
        while (!s.empty()) {
            auto p = s.begin();

            int cost = p->first;
            int node = p->second;

            s.erase(p);
            for (auto [adjNode, weight] : adj[node]) {

                if (cost + weight < result[adjNode]) {
                    auto it = s.find({result[adjNode], adjNode});

                    if (it != s.end()) {
                        s.erase({result[adjNode], adjNode});
                    }

                    result[adjNode] = cost + weight;
                    s.insert({result[adjNode], adjNode});
                }
            }
        }

        int ans = -1;
        for (int i = 1; i <= n; i++) {
            if (result[i] != INT_MAX) {
                ans = max(ans, result[i]);
            } else {
                return -1;
            }
        }

        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/network-delay-time/)