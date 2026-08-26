# Build a Matrix With Conditions

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given a  **positive**  integer `k`. You are also given:

- a 2D integer array rowConditions of size n where rowConditions[i] = [abovei, belowi], and
- a 2D integer array colConditions of size m where colConditions[i] = [lefti, righti].

The two arrays contain integers from `1` to `k`.

You have to build a `k x k` matrix that contains each of the numbers from `1` to `k`  **exactly once**. The remaining cells should have the value `0`.

The matrix should also satisfy the following conditions:

- The number abovei should appear in a row that is strictly above the row at which the number belowi appears for all i from 0 to n - 1.
- The number lefti should appear in a column that is strictly left of the column at which the number righti appears for all i from 0 to m - 1.

Return  ***any**  matrix that satisfies the conditions*. If no answer exists, return an empty matrix.

 

 **Example 1:** 

```
Input: k = 3, rowConditions = [[1,2],[3,2]], colConditions = [[2,1],[3,2]]
Output: [[3,0,0],[0,0,1],[0,2,0]]
Explanation: The diagram above shows a valid example of a matrix that satisfies all the conditions.
The row conditions are the following:
- Number 1 is in row 1, and number 2 is in row 2, so 1 is above 2 in the matrix.
- Number 3 is in row 0, and number 2 is in row 2, so 3 is above 2 in the matrix.
The column conditions are the following:
- Number 2 is in column 1, and number 1 is in column 2, so 2 is left of 1 in the matrix.
- Number 3 is in column 0, and number 2 is in column 1, so 3 is left of 2 in the matrix.
Note that there may be multiple correct answers.

```

 **Example 2:** 

```
Input: k = 3, rowConditions = [[1,2],[2,3],[3,1],[2,3]], colConditions = [[2,1]]
Output: []
Explanation: From the first two conditions, 3 has to be below 1 but the third conditions needs 3 to be above 1 to be satisfied.
No matrix can satisfy all the conditions, so we return the empty matrix.

```

 

 **Constraints:** 

- 2 <= k <= 400
- 1 <= rowConditions.length, colConditions.length <= 104
- rowConditions[i].length == colConditions[i].length == 2
- 1 <= abovei, belowi, lefti, righti <= k
- abovei != belowi
- lefti != righti

## Solution

**Language:** C++  
**Runtime:** 8 ms (beats 83.47%)  
**Memory:** 61 MB (beats 90.59%)  
**Submitted:** 2026-08-26T13:17:50.776Z  

```cpp
class Solution {
public:
    vector<int> topoSort(int k, vector<vector<int>>& conditions) {
        vector<int> indegree(k + 1, 0);
        vector<vector<int>> adj(k + 1, vector<int>());
        for (const auto& condition : conditions) {
            int u = condition[0];
            int v = condition[1];

            adj[u].push_back(v);
            indegree[v]++;
        }

        vector<int> order;
        queue<int> q;
        for (int i = 1; i < k + 1; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            order.push_back(node);
            for (const auto& neighbour : adj[node]) {
                indegree[neighbour]--;

                if (indegree[neighbour] == 0) {
                    q.push(neighbour);
                }
            }
        }

        if (order.size() < k) {
            return {};
        }

        return order;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions,
                                    vector<vector<int>>& colConditions) {

        vector<int> row = topoSort(k, rowConditions);
        vector<int> column = topoSort(k, colConditions);

        if (row.empty() || column.empty()) {
            return {};
        }

        vector<vector<int>> result(k, vector<int>(k, 0));
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                if (row[i] == column[j]) {
                    result[i][j] = row[i];
                }
            }
        }

        return result;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/build-a-matrix-with-conditions/)