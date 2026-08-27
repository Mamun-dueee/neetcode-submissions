class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int bestBuy = INT_MAX;
        int maxProfit = 0;
        for(int p : prices){
            if(p < bestBuy){
                bestBuy = p;
            }
            else{
                maxProfit = max(maxProfit, p - bestBuy);
            }
        }
        return maxProfit;
        
    }
};
