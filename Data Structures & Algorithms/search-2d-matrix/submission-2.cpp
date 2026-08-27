class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int m = mat.size(), n = mat[0].size();
        int r = 0, c = mat[0].size()-1;

        while(r < m && c >=0 ){
            if(mat[r][c] > target){
                c--;
            }
            else if(mat[r][c] < target){
                r++;
            }
            else{
                return true;
            }
        }
        return false;

    }
};
