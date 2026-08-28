class Solution {
    //Map each course to its prerequisites
    unordered_map<int, vector<int>> preMap;
    // Store the visited courses
    unordered_set<int> visited;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(int i = 0; i < numCourses; i++){
            preMap[i] = {};
        }
        for(auto prs : prerequisites){
            preMap[prs[0]].push_back(prs[1]);
        }
        for(int c = 0; c < numCourses; c++){
            if(dfs(c) == false){
                return false;
            }
        }
        return true;
    }

    bool dfs(int crs){
        if(visited.count(crs)){
            return false;
        }
        if(preMap[crs].empty()){
            return true;
        }
        visited.insert(crs);
        for(int prs : preMap[crs]){
            if(dfs(prs) == false){
                return false;
            }
        }
        visited.erase(crs);
        preMap[crs].clear();
        return true;
    }
};
