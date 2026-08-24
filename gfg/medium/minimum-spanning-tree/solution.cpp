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