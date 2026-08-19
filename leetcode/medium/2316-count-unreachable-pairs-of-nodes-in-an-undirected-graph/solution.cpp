class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int i) {
        if (i == parent[i]) {
            return i;
        }

        return parent[i] = find(parent[i]);
    }

    void union_find(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);

        if (x_parent != y_parent) {
            if (rank[x_parent] > rank[y_parent]) {
                parent[y_parent] = x_parent;
            } else if (rank[y_parent] > rank[x_parent]) {
                parent[x_parent] = y_parent;
            }

            else {
                parent[y_parent] = x_parent;
                rank[x_parent]++;
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }

        // create union of edges
        for (const auto& pairs : edges) {
            union_find(pairs.front(), pairs.back());
        }

        // find components
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++) {
            m[find(i)]++;
        }

        long long remaining = n;
        long long count = 0;

        for (const auto& it : m) {
            count += (it.second) * (remaining - it.second);
            remaining -= it.second;
        }

        return count;
    }
};