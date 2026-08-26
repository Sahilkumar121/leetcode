class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {

                    if (source == destination) return true;

        vector<vector<int>> adj(n, vector<int>());
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);
        queue<int> q;
        q.push(source);
        visited[source] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (const auto& neighbour : adj[node]) {
                if (neighbour == destination) {
                    return true;
                }

                if (!visited[neighbour]) {
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }

        return false;
    }
};