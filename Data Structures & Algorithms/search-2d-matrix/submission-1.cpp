class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int m = mat.size(), n = mat[0].size();
        int left = 0, right = m*n - 1;

        while(left <= right){
            int mid = left + (right-left)/2;
            int row = mid / n, col = mid % n;
            if(target > mat[row][col]){
                left = mid+1;
            }
            else if(target < mat[row][col]){
                right = mid-1;
            }
            else{
                return true;
            }
        }
        return false;
    }
};
