class Solution {
public:
    int cntHighBits(int x){
        int b = 0;
        while(x > 0){
            b++;
            x = x & (x-1);
        }
        return b;
    }
    vector<int> countBits(int n) {
        vector<int> res;
        for(int i = 0; i <= n; i++){
            res.push_back(cntHighBits(i));
        }
        return res;
    }
};
