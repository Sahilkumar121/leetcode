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
