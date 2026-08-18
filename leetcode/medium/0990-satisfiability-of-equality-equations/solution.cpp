class Solution {
public:
    int find(int i, int parent[]) {
        if (parent[i] == i) {
            return i;
        }

        return parent[i] = find(parent[i], parent);
    }

    void union_find(int x, int y, int parent[], int rank[]) {
        int x_parent = find(x, parent);
        int y_parent = find(y, parent);

        if (x_parent != y_parent) {
            if (rank[x_parent] > rank[y_parent]) {
                parent[y_parent] = x_parent;
            } else if (rank[x_parent] < rank[y_parent]) {
                parent[x_parent] = y_parent;
            } else {
                parent[y_parent] = x_parent;
                x_parent++;
            }
        }
    }
    bool equationsPossible(vector<string>& equations) {

        int parent[26];
        int rank[26] = {0};

        for (int i = 0; i < 26; i++) {
            parent[i] = i;
        }

        for (const auto& equation : equations) {
            if (equation[1] == '=') {
                int x_position = equation[0] - 'a';
                int y_position = equation[3] - 'a';

                union_find(x_position, y_position, parent, rank);
            }
        }

        for (const auto& equation : equations) {
            if (equation[1] == '!') {
                int x_position = find(equation[0] - 'a', parent);
                int y_position = find(equation[3] - 'a', parent);

                if (x_position == y_position) {
                    return false;
                }
            }
        }

        return true;
    }
};