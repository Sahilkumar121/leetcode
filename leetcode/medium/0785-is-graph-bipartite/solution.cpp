class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {

        int V = graph.size();
        vector<int> color(V, -1);

        for (int i = 0; i < V; i++) {
            if (color[i] != -1) {
                continue;
            }
            queue<int> q;
            q.push(i);
            color[i] = 1;

            while (!q.empty()) {
                int element = q.front();
                q.pop();

                for (const auto& neighbour : graph[element]) {
                    if (color[neighbour] == color[element]) {
                        return false;
                    }

                    if (color[neighbour] == -1) {
                        color[neighbour] = 1 - color[element];
                        q.push(neighbour);
                    }
                }
            }
        }

        return true;
    }
};