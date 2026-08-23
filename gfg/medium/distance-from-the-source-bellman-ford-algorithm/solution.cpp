class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        
        int max_dis = pow(10, 8);
        vector<int> dis(V, max_dis);
        dis[src] = 0;

        int iterate = V - 1;
        while (iterate--)
        {
            for (const auto &edge : edges)
            {
                int u = edge[0];
                int v = edge[1];
                int weight = edge[2];

                if (dis[u] != max_dis && dis[u] + weight < dis[v])
                {
                    dis[v] = dis[u] + weight;
                }
            }
        }

        // check for negative cycle (if last in V chance if dis is still less then it has negative cycle)
        for (const auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int weight = edge[2];

            if (dis[u] != max_dis && dis[u] + weight < dis[v])
            {
                return {-1};
            }
        }

        return dis;

    }
};
