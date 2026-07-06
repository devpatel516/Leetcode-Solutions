class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int stock=prices[0];
        int profit=INT_MIN;
        for(int i=0;i<prices.size();i++){
            if(prices[i]<stock){
                stock=prices[i];
            }
            profit=max(profit,abs(stock-prices[i]));
        }
        return profit;
    }
};