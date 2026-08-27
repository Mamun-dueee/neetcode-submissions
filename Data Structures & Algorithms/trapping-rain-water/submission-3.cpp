class Solution {
public:
    int trap(vector<int>& h) {
        int l = 0, r = h.size()-1;
        int lmaxSoFar = h[l], rmaxSoFar = h[r];

        int res = 0; 
        while(l < r){
            if(h[l] < h[r]){
                l++;
                lmaxSoFar = max(lmaxSoFar, h[l]);
            }
            else{
                r--;
                rmaxSoFar = max(rmaxSoFar, h[r]);
            }
            res += lmaxSoFar - h[l];
            res += rmaxSoFar - h[r];
        }
        return res;
        
    }
};