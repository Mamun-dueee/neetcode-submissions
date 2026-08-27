class Solution {
public:
    int cntBits(int x){
        int res = 0; 
        while(x > 0){
            x = x & (x-1);
            res++;
        }
        return res;
    }
    vector<int> countBits(int n) {
        vector<int> ans; 
        for(int i = 0; i <= n; i++){
            ans.push_back(cntBits(i));
        }
        return ans; 
        
    }
};