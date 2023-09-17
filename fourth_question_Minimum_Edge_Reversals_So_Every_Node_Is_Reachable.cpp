class Solution {
public:
    void dfs(int node, int &node_cost, int present_depth, vector<vector<pair<int, int>>> &adj, vector<bool> &visited, vector<int> &cost, vector<int> &depth){
        visited[node] = true;
        depth[node] = present_depth;
        for(auto it : adj[node]){
            if(visited[it.first] == false){
                cost[it.first] = cost[node] + it.second;
                node_cost += it.second;
                dfs(it.first, node_cost, present_depth + 1, adj, visited, cost, depth);
            }
        }
    }
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges){
        //adj is to construct the graph
        //for every node, we will store a vector which will have the nodes connected to it along with the cost associated to go to that node
        vector<vector<pair<int, int>>> adj(n);
        
        for(int i = 0; i < edges.size(); i++){
            int x = edges[i][0], y = edges[i][1];
            //it does not cost anything for traversing from x to y as there is an edge from x to y
            //it costs one unit for traversing from y to x as we need to reverse the edge.
            adj[x].push_back(make_pair(y, 0));
            adj[y].push_back(make_pair(x, 1));
        }
        int start_node = 0, initial_node_cost = 0, initial_depth = 0;
        //depth vector is to calculate the depth of every node from the start_node
        //cost vector is to calculate the cost to visit every node from start_node
        vector<int> depth(n, 0);
        vector<bool> visited(n, false);
        vector<int> cost(n, 0);
        dfs(start_node, initial_node_cost, initial_depth, adj, visited, cost, depth);
        
        //this is to store the cost associated with each node to visit all other nodes.
        vector<int> ans(n, 0);
        //start_node cost is initial_node_cost (after DFS initial_node_cost will be updated from 0).
        ans[start_node] = initial_node_cost;
        for(int i = 0; i < n; i++){
            if(i == start_node){
                continue;
            }
            //cost_of_node2_to_start_node is the cost in travelling from ith node to start_node
            //remaining is the cost to travel from start_node to all nodes excluding the (cost of travel from start_node to ith node)
            int cost_of_node2_to_start_node = depth[i] - cost[i];
            int remaining = initial_node_cost - cost[i];
            //cost_of_node2_to_start_node + remaining is the total cost associated with the ith node to travel all nodes
            ans[i] = cost_of_node2_to_start_node + remaining;
        }
        return ans;
    }
};
