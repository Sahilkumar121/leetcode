# Bipartite Graph

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given a Graph with  **V**  vertices (Numbered from  **0**  to  **V-1**) and  **E**  edges. Check whether the graph is  **bipartite**  or not.

A **bipartite graph** can be colored with two colors such that  **no two**   **adjacent**   **vertices**  share the  **same color**. This means we can divide the graph’s vertices into two distinct sets where:

- All edges connect vertices from one set to vertices in the other set.
- No edges exist between vertices within the same set.

 **Examples:** 

```
Input: V = 3, edges[][] = [[0, 1], [1,2]]

Output: true
Explanation: The given graph can be colored in two colors so, it is a bipartite graph.

```

```
Input: V = 4, edges[][] = [[0, 3], [1, 2], [3, 2], [0, 2]]

Output: false 
Explanation: The given graph cannot be colored in two colors such that color of adjacent vertices differs. 
```

**Constraints:
**1 ≤ V ≤ 2 * 105
1 ≤ edges.size() ≤ 105
1 ≤ edges[i][j] ≤ 105

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-08-15T16:08:34.609Z  

```cpp
class Solution {
	public:
	bool dfs(vector<vector<int>> &adj, int u, vector<int> &color, int curr_color)
	{
		color[u] = curr_color;
		
		for (const auto &neighbour : adj[u])
			{
			if (color[neighbour] == curr_color)
				{
				return false;
			}
			
			if (color[neighbour] == -1)
				{
				if (dfs(adj, neighbour, color, 1 - curr_color) == false)
					{
					return false;
				}
			}
		}
		
		return true;
	}
	bool isBipartite(int V, vector<vector<int>> &edges) {
		// Code here
		
		vector<vector<int>> adj(V, vector<int>());
		
		for (const auto &edge : edges)
			{
			adj[edge.front()].push_back(edge.back());
			adj[edge.back()].push_back(edge.front());
		}
		
		vector<int> color(V, -1);
		// green - 0     red - 1
		
		for (int i = 0; i < V; i++)
			{
			if (color[i] == -1)
				{
				if (dfs(adj, i, color, 1) == false)
					{
					return false;
				}
			}
		}
		
		return true;
		
	}
};

```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/bipartite-graph/1)