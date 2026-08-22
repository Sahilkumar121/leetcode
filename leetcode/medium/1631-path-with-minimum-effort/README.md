# Path With Minimum Effort

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are a hiker preparing for an upcoming hike. You are given `heights`, a 2D array of size `rows x columns`, where `heights[row][col]` represents the height of cell `(row, col)`. You are situated in the top-left cell, `(0, 0)`, and you hope to travel to the bottom-right cell, `(rows-1, columns-1)` (i.e.,  **0-indexed**). You can move  **up**,  **down**,  **left**, or  **right**, and you wish to find a route that requires the minimum  **effort**.

A route's  **effort**  is the  **maximum absolute difference**  in heights between two consecutive cells of the route.

Return  *the minimum  **effort**  required to travel from the top-left cell to the bottom-right cell.* 

 

 **Example 1:** 

```
Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
Output: 2
Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.

```

 **Example 2:** 

```
Input: heights = [[1,2,3],[3,8,4],[5,3,5]]
Output: 1
Explanation: The route of [1,2,3,4,5] has a maximum absolute difference of 1 in consecutive cells, which is better than route [1,3,5,3,5].

```

 **Example 3:** 

```
Input: heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
Output: 0
Explanation: This route does not require any effort.

```

 

 **Constraints:** 

- rows == heights.length
- columns == heights[i].length
- 1 <= rows, columns <= 100
- 1 <= heights[i][j] <= 106

## Solution

**Language:** C++  
**Runtime:** 58 ms (beats 48.77%)  
**Memory:** 24.5 MB (beats 56.51%)  
**Submitted:** 2026-08-22T04:58:45.389Z  

```cpp
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
```

---

[View on LeetCode](https://leetcode.com/problems/path-with-minimum-effort/)