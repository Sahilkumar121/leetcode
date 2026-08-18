class Solution {
public:
    int find(int i, vector<int>& parent) {
        if (parent[i] == i) {
            return i;
        }

        return parent[i] = find(parent[i], parent);
    }

    void union_find(int x, int y, vector<int>& parent) {
        int x_parent = find(x, parent);
        int y_parent = find(y, parent);

        if (x_parent != y_parent) {
            parent[y_parent] = x_parent;
        }
    }
    bool equationsPossible(vector<string>& equations) {

        {
            vector<int> parent(26, -1);
            for (int i = 0; i < 26; i++) {
                parent[i] = i;
            }

            stack<string> not_equal_equation;

            for (const auto& equation : equations) {
                if (equation[1] == '=') {
                    int x_position = equation[0] - 'a';
                    int y_position = equation[3] - 'a';

                    union_find(x_position, y_position, parent);
                } else {
                    not_equal_equation.push(equation);
                }
            }

            while (!not_equal_equation.empty()) {
                string s = not_equal_equation.top();
                not_equal_equation.pop();

                int x_parent = find(s[0] - 'a', parent);
                int y_parent = find(s[3] - 'a', parent);

                if (x_parent == y_parent) {
                    return false;
                }
            }

            return true;
        }
    }
};