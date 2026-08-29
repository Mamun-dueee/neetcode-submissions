class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses);
        vector<vector<int>> adj(numCourses);

        for(auto pr : prerequisites){
            indegree[pr[1]]++;
            adj[pr[0]].push_back(pr[1]);
        }

        queue<int> q; 
        for(int c = 0; c < numCourses; c++){
            if(indegree[c] == 0){
                q.push(c);
            }
        }

        vector<int> res;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            res.push_back(cur);

            for(int nei : adj[cur]){
                indegree[nei]--;
                if(indegree[nei] == 0){
                    q.push(nei);
                }
            }
        }

        if(res.size() == numCourses){
            reverse(res.begin(), res.end());
            return res;
        }
        else{
            return {};
        }
    }
};
