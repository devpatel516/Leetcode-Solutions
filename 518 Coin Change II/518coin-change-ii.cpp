class Solution {
public:
    int func(int i,int amount,vector<int>& coins,vector<vector<int>> &dp){
        if(i<0){
            return 0;
        }
        if(amount==0){
            return 1;
        }
        if(dp[i][amount]!=-1){
            return dp[i][amount];
        }
        int nottake=func(i-1,amount,coins,dp);
        int take=0;
        if(coins[i]<=amount){
            take=func(i,amount-coins[i],coins,dp);
        }
        return dp[i][amount]=take+nottake;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        int ans=func(coins.size()-1,amount,coins,dp);
        return ans;
    }
};