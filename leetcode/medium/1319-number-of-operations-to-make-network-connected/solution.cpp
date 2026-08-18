class Solution {
public:
    int find(int i, vector<int>& parent) {
        if (parent[i] == i) {
            return i;
        }

        return parent[i] = find(parent[i], parent);
    }

    void union_find(int x, int y, vector<int>& parent, vector<int>& rank) {
        int x_parent = find(x, parent);
        int y_parent = find(y, parent);

        if (x_parent != y_parent) {
            if (rank[x_parent] > rank[y_parent]) {
                parent[y_parent] = x_parent;
            } else if (rank[x_parent] < rank[y_parent]) {
                parent[x_parent] = y_parent;
            } else {
                parent[y_parent] = x_parent;
                rank[x_parent]++;
            }
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) {
            return -1;
        }

        vector<int> parent(n);
        vector<int> rank(n, 0);

        for (size_t i = 0; i < n; ++i) {
            parent[i] = i;
        }

        // create union connection of all computers
        for (const auto& pairs : connections) {
            union_find(pairs.front(), pairs.back(), parent, rank);
        }

        int extra_wire = 0;

        for (size_t i = 0; i < n; ++i) {
            if (parent[i] == i) {
                extra_wire++;
            }
        }

        return extra_wire - 1;
    }
};