class Solution {
public:
    int fun(int i,int j,vector<vector<int>>& obstacleGrid,vector<vector<int>> &dp){
        if(i==0 && j==0){
            return 1;
        }
        if(i<0 || j<0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(obstacleGrid[i][j]==1){
            return 0;
        }

        int left=fun(i,j-1,obstacleGrid,dp);
        int up=fun(i-1,j,obstacleGrid,dp);

        return dp[i][j]=left+up;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        // if(n==1){
        //     if(obstacleGrid[0][0]==0){
        //         return 1;
        //     }
        //     else{
        //         return 0;
        //     }
        // }

        if(obstacleGrid[0][0]==1 || obstacleGrid[m-1][n-1]==1){
            return 0;
        }
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return fun(m-1,n-1,obstacleGrid,dp);
    }
};