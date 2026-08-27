class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int m = mat.size(), n = mat[0].size();

        // Search for row
        int top = 0, bottom = m-1;
        while(top+1 < bottom){
            int mid = top + (bottom-top)/2;
            if(mat[mid][0] == target){
                return true;
            }
            else if(mat[mid][0] < target){
                top = mid;
            }
            else{
                bottom = mid;
            }
        }
        int res_row = 0;
        if(target < mat[bottom][0]){
            res_row = top;
        }
        else{
            res_row = bottom;
        }

        int left = 0, right = n - 1;
        while(left+1 < right){
            int mid = left + (right-left)/2;
            if(mat[res_row][mid] == target){
                return true;
            }
            else if(mat[res_row][mid] < target){
                left = mid;
            }
            else{
                right = mid;
            }
        }
        if(mat[res_row][left] == target) return true;
        if(mat[res_row][right] == target) return true;

        return false;
        
    }
};
