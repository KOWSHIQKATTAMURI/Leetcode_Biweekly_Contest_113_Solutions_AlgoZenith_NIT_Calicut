import java.util.*;

class Solution {
    int node_cost;
    public void dfs(int node, int present_depth, ArrayList<ArrayList<Pair<Integer, Integer>>> adj, boolean[] visited, int[] cost, int[] depth){
        visited[node] = true;
        depth[node] = present_depth;
        for(Pair<Integer, Integer> it : adj.get(node)){
            if(visited[it.getKey()] == false){
                cost[it.getKey()] = cost[node] + it.getValue();
                node_cost += it.getValue();
                dfs(it.getKey(), present_depth + 1, adj, visited, cost, depth);
            }
        }
    }
    public int[] minEdgeReversals(int n, int[][] edges){
        ArrayList<ArrayList<Pair<Integer, Integer>>> adj = new ArrayList<>();
        
        for(int i = 0; i < n; i++){
            adj.add(new ArrayList<>());
        }
        
        for(int i = 0; i < edges.length; i++){
            int x = edges[i][0], y = edges[i][1];
            adj.get(x).add(new Pair<>(y, 0));
            adj.get(y).add(new Pair<>(x, 1));
        }
        int start_node = 0, initial_depth = 0;
        node_cost = 0;
        int[] depth = new int[n];
        boolean[] visited = new boolean[n];
        int[] cost = new int[n];
        dfs(start_node, initial_depth, adj, visited, cost, depth);
        
        int[] ans = new int[n];
        ans[start_node] = node_cost;
        for(int i = 0; i < n; i++){
            if(i == start_node){
                continue;
            }
            int cost_of_node2_to_start_node = depth[i] - cost[i];
            int remaining = node_cost - cost[i];
            ans[i] = cost_of_node2_to_start_node + remaining;
        }
        return ans;
    }
}
