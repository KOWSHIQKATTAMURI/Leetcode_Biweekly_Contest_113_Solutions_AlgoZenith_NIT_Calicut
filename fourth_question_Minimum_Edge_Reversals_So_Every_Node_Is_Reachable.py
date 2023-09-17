class Solution:
    def __init__(self):
        self.adj = []
        self.visited = []
        self.cost = []
        self.depth = []
        self.node_cost = 0

    def dfs(self, node, present_depth):
        self.visited[node] = True
        self.depth[node] = present_depth
        for it in self.adj[node]:
            if not self.visited[it[0]]:
                self.cost[it[0]] = self.cost[node] + it[1]
                self.node_cost += it[1]
                self.dfs(it[0], present_depth + 1)

    def minEdgeReversals(self, n, edges):
        self.adj = [[] for _ in range(n)]
        
        for i in range(len(edges)):
            x, y = edges[i]
            self.adj[x].append((y, 0))
            self.adj[y].append((x, 1))

        start_node = 0
        initial_depth = 0
        self.depth = [0]*n
        self.visited = [False]*n
        self.cost = [0]*n
        self.dfs(start_node, initial_depth)
        
        ans = [0]*n
        ans[start_node] = self.node_cost
        for i in range(n):
            if i == start_node:
                continue
            cost_of_node2_to_start_node = self.depth[i] - self.cost[i]
            remaining = self.node_cost - self.cost[i]
            ans[i] = cost_of_node2_to_start_node + remaining

        return ans
