class Solution {
    vector<vector<int>> adj;
    unordered_set<int> visited;
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() > n-1){
            return false;
        }
        
        adj.assign(n, vector<int>());
        for(auto ed : edges){
            adj[ed[0]].push_back(ed[1]);
            adj[ed[1]].push_back(ed[0]);
        }

        if(!dfs(0, -1)){
            return false;
        }

        return visited.size() == n; 
    }

    bool dfs(int node, int parent){
        if(visited.count(node)){
            return false;
        }

        visited.insert(node);
        for(int nei : adj[node]){
            if(nei == parent){
                continue;
            }
            if(!dfs(nei, node)){
                return false;
            }
        }
        return true;

    }
};
