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
