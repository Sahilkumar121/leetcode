class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int, int>>> adj(n + 1, vector<pair<int, int>>());
        for (const auto& vertices : times) {
            adj[vertices[0]].push_back({vertices[1], vertices[2]});
        }

        set<pair<int, int>> s;
        s.insert({0, k});

        vector<int> result(n + 1, INT_MAX);
        result[k] = 0;
        while (!s.empty()) {
            auto p = s.begin();

            int cost = p->first;
            int node = p->second;

            s.erase(p);
            for (auto [adjNode, weight] : adj[node]) {

                if (cost + weight < result[adjNode]) {
                    auto it = s.find({result[adjNode], adjNode});

                    if (it != s.end()) {
                        s.erase({result[adjNode], adjNode});
                    }

                    result[adjNode] = cost + weight;
                    s.insert({result[adjNode], adjNode});
                }
            }
        }

        int ans = -1;
        for (int i = 1; i <= n; i++) {
            if (result[i] != INT_MAX) {
                ans = max(ans, result[i]);
            } else {
                return -1;
            }
        }

        return ans;
    }
};