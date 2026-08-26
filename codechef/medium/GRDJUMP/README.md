# GRDJUMP

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Grid Jump

You are standing at point $(0, 0)$ of the 2D coordinate grid. You would like to reach point $(A, B)$.

You have the following movements available to you:

- Move either $1$ or $2$ steps right for a cost of $P$ coins. That is, you can move from $(x, y)$ to either $(x+1, y)$ or $(x+2, y)$ for a cost of $P$.
- Move either $1$ or $2$ steps up for a cost of $Q$ coins. That is, you can move from $(x, y)$ to either $(x, y+1)$ or $(x, y+2)$ for a cost of $Q$.
- Move $1$ step up and $1$ step right for a cost of $R$ coins. That is, you can move from $(x, y)$ to $(x+1, y+1)$ for a cost of $R$.

Find the minimum number of coins you need to spend in order to reach point $(A, B)$.

### Input Format
- The first line of input will contain a single integer $T$, denoting the number of test cases.
- Each test case consists of a single line of input, containing five space-separated integers $A, B, P, Q, R$ — the coordinates of the destination point, and the movement costs.
### Output Format

For each test case, output on a new line the minimum number of coins you need to move to $(A, B)$.

### Constraints
- $1 \leq T \leq 1000$
- $1 \le A, B, P, Q, R \le 100$
### Sample 1:
Input
Output

```
4
2 1 6 3 4
2 2 6 3 4
3 4 1 3 2
4 7 4 2 7

```

```
9
8
8
16

```

### Explanation:

 **Test case $1$:**  We want to reach $(2, 1)$. It's optimal to:

- Use the first type and move two steps right, with a cost of $P=6$.
- Use the second type and move one step up, with a cost of $Q=3$.

This will put us at $(2, 1)$ for a cost of $6+3 = 9$, which is the best we can do.

 **Test case $2$:**  We want to reach $(2, 2)$. It's optimal to use the third type of move (simultaneously move right and up one step each) two times, each costing $R=4$.
This will put us at $(2, 2)$ for a cost of $4+4=8$.
For the given costs, this is optimal.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-08-26T15:37:43.321Z  

```c_cpp
#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

void solve()
{
    long long A, B, P, Q, R;
    cin >> A >> B >> P >> Q >> R;

    set<pair<long long, pair<int, int>>> st;

    vector<vector<long long>> dist(A + 1, vector<long long>(B + 1, INF));

    vector<vector<int>> direction_p = {{1, 0}, {2, 0}};
    vector<vector<int>> direction_q = {{0, 1}, {0, 2}};
    vector<vector<int>> direction_r = {{1, 1}};

    dist[0][0] = 0;
    st.insert({0, {0, 0}});

    long long min_cost = -1;

    while (!st.empty())
    {
        auto it = st.begin();
        long long cost = it->first;
        int x = it->second.first;
        int y = it->second.second;
        st.erase(it);

        if (x == A && y == B)
        {
            min_cost = cost;
            break;
        }

        auto process_move = [&](int dx, int dy, long long move_cost)
        {
            int nx = x + dx;
            int ny = y + dy;

            if (nx <= A && ny <= B)
            {
                long long new_cost = cost + move_cost;

                if (new_cost < dist[nx][ny])
                {
                    if (dist[nx][ny] != INF)
                    {
                        st.erase({dist[nx][ny], {nx, ny}});
                    }

                    dist[nx][ny] = new_cost;
                    st.insert({new_cost, {nx, ny}});
                }
            }
        };

        for (const auto &d : direction_p)
            process_move(d[0], d[1], P);
        for (const auto &d : direction_q)
            process_move(d[0], d[1], Q);
        for (const auto &d : direction_r)
            process_move(d[0], d[1], R);
    }

    cout << min_cost << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (cin >> t)
    {
        while (t--)
        {
            solve();
        }
    }

    return 0;
}
```

---

[View on CodeChef](https://www.codechef.com/problems/GRDJUMP)