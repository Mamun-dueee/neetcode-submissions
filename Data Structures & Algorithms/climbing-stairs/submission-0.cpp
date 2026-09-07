class Solution {
public:
    int climbStairs(int n) {
        int res = 0; 
        int a = 1, b = 1; 
        if(n < 2 ) return 1; 

        for(int i = 2; i <= n; i++)
        {
            res = a + b; 
            a = b; 
            b = res; 
        }
        return res; 
        
    }
};
