class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lowest_buy = prices[0];
        int profit, mx_profit = 0;
        for(int i = 0; i < prices.size(); i++){
            if(prices[i]<lowest_buy){
                lowest_buy = prices[i];
            }
            //cout << lowest_buy << " " << prices[i] << endl; 
            if(prices[i] > lowest_buy){
                profit = prices[i] - lowest_buy;
                mx_profit = max(mx_profit, profit);
            }
        }
        return mx_profit;
    }
};
