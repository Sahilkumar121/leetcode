class Solution:
    
    def traversal(self,adj, u, visited, result):
        if visited[u]:
            return

        visited[u] = True

        result.append(u)


        for neighbour in adj[u]:
            if not visited[neighbour]:
                self.traversal(adj, neighbour, visited, result)
                
                
    def dfs(self, adj):
        # code here
        vertices = len(adj)
        visited = [False] * vertices
        
        result = []
        for i in range(vertices):
            self.traversal(adj, i, visited, result)
            
        return result
        
        