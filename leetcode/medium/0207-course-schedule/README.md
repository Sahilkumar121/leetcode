# Course Schedule

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

There are a total of `numCourses` courses you have to take, labeled from `0` to `numCourses - 1`. You are given an array `prerequisites` where `prerequisites[i] = [ai, bi]` indicates that you  **must**  take course `bi` first if you want to take course `ai`.

- For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.

Return `true` if you can finish all courses. Otherwise, return `false`.

 

 **Example 1:** 

```
Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.

```

 **Example 2:** 

```
Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

```

 

 **Constraints:** 

- 1 <= numCourses <= 2000
- 0 <= prerequisites.length <= 5000
- prerequisites[i].length == 2
- 0 <= ai, bi < numCourses
- All the pairs prerequisites[i] are unique.

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 19.2 MB (beats 81.73%)  
**Submitted:** 2026-08-15T14:18:32.379Z  

```cpp
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
```

---

[View on LeetCode](https://leetcode.com/problems/course-schedule/)