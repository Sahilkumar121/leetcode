class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> adj(numCourses, vector<int>());
        vector<int> inDegree(numCourses, 0);

        for (const auto &edge : prerequisites)
        {
            adj[edge.back()].push_back(edge.front());
            inDegree[edge.front()]++;
        }

        queue<int> q;

        for (int i = 0; i < numCourses; ++i)
        {
            if (inDegree[i] == 0)
            {
                q.push(i);
            }
        }

        int count = 0;

        while (!q.empty())
        {
            int element = q.front();
            q.pop();
            count++;

            for (const auto &neighbour : adj[element])
            {
                inDegree[neighbour]--;

                if (inDegree[neighbour] == 0)
                {
                    q.push(neighbour);
                }
            }
        }

        if (count != numCourses)
        {
            return false;
        }

        return true;
    
    }
};