class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {

        int V = isConnected.size();
        vector<bool> visited(V, false);

        int count = 0;

        for (int i = 0; i < V; i++) {
            queue<int> q;
            if (!visited[i]) {
                q.push(i);

                while (!q.empty()) {
                    int element = q.front();
                    q.pop();
                    visited[element] = true;

                    for (int j = 0; j < V; j++) {
                        if (isConnected[element][j] == 1 && !visited[j]) {
                            q.push(j);
                        }
                    }
                }

                count++;
            }
        }

        return count;
    }
};