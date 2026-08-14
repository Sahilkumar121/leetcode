# Topological Sort

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given a Directed Acyclic Graph (DAG) with  **V** vertices numbered from 0 to V - 1 and  **E** directed edges represented by a 2D array  **edges[][]**, where edges[i] = [u, v] denotes a directed edge from vertex u to vertex v, return a topological ordering of all the vertices.

A topological ordering is a linear ordering of the vertices such that for every directed edge u -> v, vertex u appears before vertex v in the ordering.

 **Note:** As there are multiple Topological orders possible, you may return any of them. If your returned Topological sort is correct then the output will be true else false.

 **Examples:** 

```
Input: V = 4, E = 3, edges[][] = [[3, 0], [1, 0], [2, 0]]

Output: true
Explanation: The output true denotes that the order is valid. Few valid Topological orders for the given graph are:
[3, 2, 1, 0]
[1, 2, 3, 0]
[2, 3, 1, 0]
```

```
Input: V = 6, E = 6, edges[][] = [[1, 3], [2, 3], [4, 1], [4, 0], [5, 0], [5, 2]]

Output: true
Explanation: The output true denotes that the order is valid. Few valid Topological orders for the graph are:
[4, 5, 0, 1, 2, 3]
[5, 2, 4, 0, 1, 3]
```

 **Constraints:** 
2  ≤  V  ≤  5 x 103
1  ≤  E = edges.size()  ≤  min[105, (V * (V - 1)) / 2]
0 ≤ edges[i][0], edges[i][1] < V

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-08-14T16:22:13.005Z  

```cpp
class Solution {
	public:
	static vector<vector<int>> create_adj_list(const int V, const vector<vector<int>> &edges) {
		vector<vector<int>> adj(V, vector<int>());
		
		for (const auto &edge : edges) {
			adj[edge.front()].push_back(edge.back());
		}
		
		return adj;
	}
	
	static void DFS(const vector<vector<int>> &adj, const int u, vector<bool> &visited, stack<int> &st) {
		visited[u] = true;
		
		for (const auto &neighbour : adj[u]) {
			if (!visited[neighbour]) {
				DFS(adj, neighbour, visited, st);
			}
		}
		
		st.push(u);
		
	}
	
	vector<int> topoSort(int V, vector<vector<int>> & edges) {
		// code here
		const vector<vector<int>> adj = create_adj_list(V, edges);
		
		vector<int> result;
		vector<bool> visited(V, false);
		stack<int> st;
		
		for (int i = 0; i<V; i++) {
			if (!visited[i]) {
				DFS(adj, i, visited, st);
			}
		}
		
		while (!st.empty()) {
			result.push_back(st.top());
			st.pop();
		}
		
		return result;
		
	}
};

```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/topological-sort/1)