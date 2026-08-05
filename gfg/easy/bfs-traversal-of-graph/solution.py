class Solution:
    def bfs(self, adj):
        # code here
        q = deque()
        result = []

        q.append(0)
        visited = [False for _ in range(len(adj))]
        visited[0] = True

        while len(q) > 0:
            x = q.popleft()
            result.append(x)

            for neighbour in adj[x]:
                if not visited[neighbour]:
                    q.append(neighbour)
                    visited[neighbour] = True

        return result
