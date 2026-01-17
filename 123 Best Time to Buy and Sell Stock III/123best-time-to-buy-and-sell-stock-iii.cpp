class Solution {
public:
    // int func(int i,int buy,int cap,vector<int>& prices,vector<vector<vector<int>>> &dp){
    //     int n=prices.size();
    //     if(cap==0){
    //         return 0;
    //     }
    //     if(i==n){
    //         return 0;
    //     }
    //     if(buy){
    //         return dp[i][buy][cap]=max(-prices[i]+func(i+1,0,cap,prices,dp),0+func(i+1,1,cap,prices,dp));
    //     }
    //     return dp[i][buy][cap]=max(prices[i]+func(i+1,1,cap-1,prices,dp),0+func(i+1,0,cap,prices,dp));
    // }
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size()+1,vector<vector<int>> (2,vector<int>(3,0)));

        for(int i=prices.size()-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                for(int cap=1;cap<=2;cap++){
                    if(buy){
                        dp[i][buy][cap]=max(-prices[i]+dp[i+1][0][cap],0+dp[i+1][1][cap]);
                    }
                    else{
                        dp[i][buy][cap]=max(prices[i]+dp[i+1][1][cap-1],0+dp[i+1][0][cap]);
                    }
                }
            }
        }
        return dp[0][1][2];
    }
};