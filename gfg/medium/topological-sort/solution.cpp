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
