class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<int> indeg(n);
        vector<vector<int>> adj(n);

        for(auto pr : prerequisites){
            indeg[pr[1]]++;
            adj[pr[0]].push_back(pr[1]);
        }

        queue<int> q; 
        for(int c = 0; c < n; c++){
            if(indeg[c] == 0){
                q.push(c);
            }
        }

        int finish = 0; 
        while(!q.empty()){
            int node = q.front();
            q.pop();
            finish++;

            for(int nei : adj[node]){
                indeg[nei]--;
                if(indeg[nei] == 0){
                    q.push(nei);
                }
            }
        }

        return finish == n; 
    }
};
