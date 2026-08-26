class Solution {
public:
    vector<int> topoSort(int k, vector<vector<int>>& conditions) {
        vector<int> indegree(k + 1, 0);
        vector<vector<int>> adj(k + 1, vector<int>());
        for (const auto& condition : conditions) {
            int u = condition[0];
            int v = condition[1];

            adj[u].push_back(v);
            indegree[v]++;
        }

        vector<int> order;
        queue<int> q;
        for (int i = 1; i < k + 1; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            order.push_back(node);
            for (const auto& neighbour : adj[node]) {
                indegree[neighbour]--;

                if (indegree[neighbour] == 0) {
                    q.push(neighbour);
                }
            }
        }

        if (order.size() < k) {
            return {};
        }

        return order;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions,
                                    vector<vector<int>>& colConditions) {

        vector<int> row = topoSort(k, rowConditions);
        vector<int> column = topoSort(k, colConditions);

        if (row.empty() || column.empty()) {
            return {};
        }

        vector<vector<int>> result(k, vector<int>(k, 0));
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                if (row[i] == column[j]) {
                    result[i][j] = row[i];
                }
            }
        }

        return result;
    }
};