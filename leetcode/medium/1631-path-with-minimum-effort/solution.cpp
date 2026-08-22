class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int row = heights.size();
        int column = heights[0].size();

        vector<vector<int>> efforts(row, vector<int>(column, INT_MAX));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        pq.push({0, {0, 0}});
        efforts[0][0] = 0;

        array<array<int, 2>, 4> directions = {{{0, 1},
                                               {0, -1},
                                               {1, 0},
                                               {-1, 0}}};

        auto isSafe = [&](int x, int y)
        {
            return x >= 0 && x < row && y >= 0 && y < column;
        };

        while (!pq.empty())
        {
            pair<int, pair<int, int>> p = pq.top();
            pq.pop();

            int diff = p.first;
            pair<int, int> cordinates = p.second;
            int x = cordinates.first;
            int y = cordinates.second;

            if (x == row - 1 && y == column - 1)
            {
                return diff;
            }

            for (const auto &d : directions)
            {
                int x_ = x + d[0];
                int y_ = y + d[1];

                if (isSafe(x_, y_))
                {
                    int efforts_diff = abs(heights[x_][y_] - heights[x][y]);
                    int newEfforts = max(diff, efforts_diff);

                    if (newEfforts < efforts[x_][y_])
                    {
                        efforts[x_][y_] = newEfforts;
                        pq.push({newEfforts, {x_, y_}});
                    }
                }
            }
        }

        return 0;
    
    }
};