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