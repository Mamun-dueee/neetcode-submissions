class Solution {
public:
    int maxArea(vector<int>& h) {
        int maxArea = 0; 
        int l = 0, r = h.size()-1;
        while(l < r){
            int curArea = (r-l)*(min(h[l], h[r]));
            maxArea = max(maxArea, curArea);
            if(h[l] < h[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return maxArea;
    }
};