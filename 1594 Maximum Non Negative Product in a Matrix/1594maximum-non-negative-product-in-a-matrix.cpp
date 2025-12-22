class Solution {
public:
    void func(int i,int j,vector<vector<int>>& grid,long long curr,long long &ans,vector<vector<int>> &dp){
        if(grid[i][j]==0){
            long long num=0;
            ans=max(ans,num);
            dp[i][j]=ans;
            return ;
        }
        curr*=grid[i][j];

        if(i==0 && j==0){
            ans=max(ans,curr);
            dp[i][j]=ans;
            return ;
        }
        if(dp[i][j]!=-1){
            return;
        }
        if(i>0){
            func(i-1,j,grid,curr,ans,dp);
        }
        if(j>0){
            func(i,j-1,grid,curr,ans,dp);
        }
    }
    int maxProductPath(vector<vector<int>>& grid) {
        int mod=1000000007;
        long long ans=-1;
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        func(m-1,n-1,grid,1,ans,dp);
        return ans%mod;
    }
};