class Solution {
    unordered_set<int> visited;
    vector<vector<int>> adj;
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n-1){
            return false;
        }
        adj.assign(n, vector<int>());
        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // BFS
        queue<pair<int, int>> q; 
        q.push({0, -1});
        while(!q.empty()){
            int curNode = q.front().first;
            int parent = q.front().second;
            q.pop();
            if(visited.count(curNode)){
                return false;
            }
            visited.insert(curNode);

            for(int nei : adj[curNode]){
                if(nei == parent){
                    continue;
                }
                q.push({nei, curNode});
            }

        }

        return visited.size() == n; 
    }
};
