# Dijkstra Algorithm

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an undirected, weighted graph with  **V** vertices numbered from 0 to V-1 and  **E** edges, represented by 2d array  **edges[][]**, where edges[i]=[u, v, w] represents the edge between the nodes u and v having w weight.
Find the shortest distance of all the vertices from the source vertex  **src**, and return an array of integers where the ith element denotes the shortest distance between ith node and source vertex src.

 **Note:** The Graph is connected and doesn't contain any negative weight edge.
It is guaranteed that all the shortest distance will fit in a 32-bit integer.

 **Examples:** 

```
Input: V = 3, edges[][] = [[0, 1, 1], [1, 2, 3], [0, 2, 6]], src = 2
Output: [4, 3, 0]
Explanation:

Shortest Paths:
For 2 to 0 minimum distance will be 4. By following path 2 -> 1 -> 0
For 2 to 1 minimum distance will be 3. By following path 2 -> 1
For 2 to 2 minimum distance will be 0. By following path 2 -> 2

```

```
Input: V = 5, edges[][] = [[0, 1, 4], [0, 2, 8], [1, 4, 6], [2, 3, 2], [3, 4, 10]], src = 0
Output: [0, 4, 8, 10, 10]
Explanation: 

Shortest Paths: 
For 0 to 1 minimum distance will be 4. By following path 0 -> 1
For 0 to 2 minimum distance will be 8. By following path 0 -> 2
For 0 to 3 minimum distance will be 10. By following path 0 -> 2 -> 3 
For 0 to 4 minimum distance will be 10. By following path 0 -> 1 -> 4
```

 **Constraints:** 
1 ≤ V ≤ 106
1 ≤ E = edges.size() ≤ 106
0 ≤ edges[i][0], edges[i][1] ≤ V-1
0 ≤ edges[i][2] ≤ 104
0 ≤ src < V

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-08-20T03:50:14.440Z  

```cpp
class Solution {
	public:
	vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
		// Code here
		
		vector<vector<pair<int, int>> > adj(V, vector<pair<int, int>> ());
		for (const auto &pairs : edges)
			{
			adj[pairs[0]].push_back({pairs[1], pairs[2]});
			adj[pairs[1]].push_back({pairs[0], pairs[2]});
		}
		
		vector<int> result(V, INT_MAX);
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
		pq.push({0, src});
		result[src] = 0;
		
		while (!pq.empty())
			{
			pair<int, int> p = pq.top();
			pq.pop();
			
			int cost = p.first;
			int node = p.second;
			
			for (const auto &neighbour : adj[node])
				{
				if (cost + neighbour.second < result[neighbour.first])
					{
					result[neighbour.first] = cost + neighbour.second;
					pq.push({result[neighbour.first], neighbour.first});
				}
			}
		}
		
		return result;
		
	}
};

```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1)