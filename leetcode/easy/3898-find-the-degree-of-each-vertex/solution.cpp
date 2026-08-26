class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {

        int n = matrix.size();
        vector<vector<int>> adj(n, vector<int>());
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 1) {
                    adj[i].push_back(j);
                }
            }
        }

        vector<int> result(n, 0);
        for (int i = 0; i < n; i++) {
            result[i] = adj[i].size();
        }

        return result;
    }
};