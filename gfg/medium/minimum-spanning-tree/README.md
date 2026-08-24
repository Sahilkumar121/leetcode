# Minimum Spanning Tree

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given a weighted, undirected, and connected graph with  **V**  vertices and a 2D array **edges[][]**, where each element edges[i] = [u, v, w] represents an edge between vertices u and v with weight w, return the sum of the weights of all edges in the graph's Minimum Spanning Tree (MST).

```
Input: V = 3, E = 3, Edges = [[0, 1, 5], [1, 2, 3], [0, 2, 1]]
 
Output: 4
Explanation:

The Spanning Tree resulting in a weight
of 4 is shown above.
```

```
Input: V = 2, E = 1, Edges = [[0 1 5]]

 

Output: 5 
Explanation: Only one Spanning Tree is possible which has a weight of 5.

```

**Constraints:
**2 ≤ V ≤ 1000
V-1 ≤ E ≤ (V*(V-1))/2
1 ≤ w ≤ 1000
The graph is connected and doesn't contain self-loops & multiple edges.

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-08-24T09:21:51.110Z  

```cpp
class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        
        // adj vector
        vector<vector<pair<int, int>>> adj(V, vector<pair<int, int>>());
        for (const auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        vector<bool> visited(V, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // wt, node
        pq.push({0, 0});

        int sum = 0;
        while (!pq.empty())
        {
            pair<int, int> p = pq.top();
            pq.pop();

            int cost = p.first;
            int node = p.second;

            if (visited[node])
            {
                continue;
            }

            visited[node] = true;
            sum += cost;

            for (const auto &neighbour : adj[node])
            {
                int v = neighbour.first;
                int wt = neighbour.second;

                if (!visited[v])
                {
                    pq.push({wt, v});
                }
            }
        }

        return sum;

    }
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1)