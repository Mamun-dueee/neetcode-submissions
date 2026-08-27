class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& A) {
        int n = A.size();
        sort(A.begin(), A.end());
        vector<vector<int>> res;

        for(int i = 0; i <= n-3; i++){
            if(i > 0 && A[i] == A[i-1]){
                continue;
            }
            int j = i+1, k = n-1;
            while(j < k){
                int sum = A[i]+A[j]+A[k];

                if(sum == 0){
                    res.push_back({A[i], A[j], A[k]});
                    //if equal A[j]  and A[j+1] do not put in res
                    while(j < k && A[j] == A[j+1]) j++;
                
                    while(j < k && A[k] == A[k-1]) k--;
                    
                    j++, k--;
                    
                }
                else if(sum > 0){
                    k--;
                }
                else{
                    j++;
                }

            }
        }
        return res;
        
    }
};
