class Solution {
public:
    int trap(vector<int>& H) {
        int n = H.size();
        int maxLeft = H[0], maxRight = H[n-1];
        int res = 0;

        int left = 0, right = n-1;
        while(left < right){
            if(H[left] < H[right]){
                maxLeft = max(maxLeft, H[left]);
                int cur = maxLeft - H[left];
                res += cur;
                left++;
            }
            else{
                maxRight = max(maxRight, H[right]);
                int cur = maxRight - H[right];
                res += cur;
                right--;
            }
        }
        return res;
        
    }
};
