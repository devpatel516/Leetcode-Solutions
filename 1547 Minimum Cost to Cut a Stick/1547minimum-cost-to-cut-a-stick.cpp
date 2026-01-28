class Solution {
public:
    int func(int i,int j,vector<int>& cuts,vector<vector<int>> &dp){
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int mini=INT_MAX;
        for(int idx=i;idx<=j;idx++){
            int temp=cuts[j+1]-cuts[i-1]+func(i,idx-1,cuts,dp)+func(idx+1,j,cuts,dp);
            mini=min(temp,mini);
        }
        return dp[i][j]=mini;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        int c=cuts.size()-2;
        vector<vector<int>> dp(c+1,vector<int> (c+1,-1));
        sort(cuts.begin(),cuts.end());
        return func(1,c,cuts,dp);
    }
};