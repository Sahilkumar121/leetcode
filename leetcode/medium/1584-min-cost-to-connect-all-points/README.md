# Min Cost to Connect All Points

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given an array `points` representing integer coordinates of some points on a 2D-plane, where `points[i] = [xi, yi]`.

The cost of connecting two points `[xi, yi]` and `[xj, yj]` is the  **manhattan distance**  between them: `|xi - xj| + |yi - yj|`, where `|val|` denotes the absolute value of `val`.

Return  *the minimum cost to make all points connected.*  All points are connected if there is  **exactly one**  simple path between any two points.

 

 **Example 1:** 

```
Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
Output: 20
Explanation: 

We can connect the points as shown above to get the minimum cost of 20.
Notice that there is a unique path between every pair of points.

```

 **Example 2:** 

```
Input: points = [[3,12],[-2,5],[-4,1]]
Output: 18

```

 

 **Constraints:** 

- 1 <= points.length <= 1000
- -106 <= xi, yi <= 106
- All pairs (xi, yi) are distinct.

## Solution

**Language:** C++  
**Runtime:** 459 ms (beats 34.34%)  
**Memory:** 134.9 MB (beats 31.03%)  
**Submitted:** 2026-08-25T03:56:18.756Z  

```cpp
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        int n = points.size();
        vector<vector<pair<int, int>>> adj(n, vector<pair<int, int>>());
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int wt = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                adj[i].push_back({j, wt});
                adj[j].push_back({i, wt});

            }
        }

        vector<bool> visited(n, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});

        int min_path = 0;
        while (!pq.empty())
        {
            pair<int, int> p = pq.top();
            pq.pop();

            int cost = p.first;
            int u = p.second;

            if (visited[u])
            {
                continue;
            }

            visited[u] = true;
            min_path += cost;

            for (const auto &neighbour : adj[u])
            {
                int v = neighbour.first;
                int wt = neighbour.second;

                if (!visited[v])
                {
                    pq.push({wt, v});
                }
            }
        }

        return min_path;
    
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/min-cost-to-connect-all-points/)