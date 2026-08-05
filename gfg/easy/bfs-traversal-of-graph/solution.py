class Solution:
    def bfs(self, adj):
        # code here
        q = deque()
        result = []

        q.append(0)
        visited = [False for _ in range(len(adj))]


        while len(q) > 0:
            x = q.popleft()
            
            if not visited[x]:
                result.append(x)
            
            visited[x] = True

            for neighbour in adj[x]:
                if not visited[neighbour]:
                    q.append(neighbour)

        return result
