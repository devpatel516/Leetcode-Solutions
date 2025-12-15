class Solution {
public:
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    int dfs(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>& vis,vector<vector<int>> &dp){
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        vis[i][j]=1;
        int n=matrix.size();
        int m=matrix[0].size();
        int ans=1;
        for(int k=0;k<4;k++){
            int nr=i+dx[k];
            int nc=j+dy[k];

            if(nr>=0 && nr<n && nc>=0 && nc<m && matrix[nr][nc]>matrix[i][j]){
                ans=max(ans,1+dfs(nr,nc,matrix,vis,dp));
            }
        }
        // vis[i][j]=0;
        return dp[i][j]=ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        vector<vector<int>> vis(n,vector<int>(m,0));
        int ans=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans=max(ans,dfs(i,j,matrix,vis,dp));
            }
        }
        return ans;
    }
};