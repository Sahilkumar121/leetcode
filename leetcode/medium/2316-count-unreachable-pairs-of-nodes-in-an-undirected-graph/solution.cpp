class Solution {
public:
    int find(int i, vector<int> &parent)
    {
        if (i == parent[i])
        {
            return i;
        }

        return parent[i] = find(parent[i], parent);
    }

    void union_find(int x, int y, vector<int> &parent, vector<int> &rank)
    {
        int x_parent = find(x, parent);
        int y_parent = find(y, parent);

        if (x_parent != y_parent)
        {
            if (rank[x_parent] > rank[y_parent])
            {
                parent[y_parent] = x_parent;
            }
            else if (rank[y_parent] > rank[x_parent])
            {
                parent[x_parent] = y_parent;
            }

            else
            {
                parent[y_parent] = x_parent;
                rank[x_parent]++;
            }
        }
    }

    long long countPairs(int n, vector<vector<int>> &edges)
    {

        vector<int> parent(n, -1);
        vector<int> rank(n, 0);
        for (int i = 0; i < n; ++i)
        {
            parent[i] = i;
        }

        // create union of edges
        for (const auto &pairs : edges)
        {
            union_find(pairs.front(), pairs.back(), parent, rank);
        }

        // find components
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            m[parent[i]]++;
        }

        int remaining = n;
        long long count = 0;

        for (const auto &pair : m)
        {
            count += pair.second * (remaining - pair.second);
            remaining -= pair.second;
        }

        return count;
    }
};