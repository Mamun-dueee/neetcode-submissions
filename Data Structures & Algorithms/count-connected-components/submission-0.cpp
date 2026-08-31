class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n, vector<int>());
        vector<bool> visited(n, false);

        for(const auto & edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int res = 0;
        for(int i = 0; i < n; i++){
            if(visited[i] == false){
                res++;
                dfs(i, visited, adj);
            }
        }

        return res;
    }

    void dfs(int node, vector<bool>& vis, vector<vector<int>>& g){
        if(vis[node] == true){
            return;
        }
        vis[node] = true;
        for(int nei : g[node]){
            dfs(nei, vis, g);
        }
        return;
    }
};
