class Solution {
public:
    double solve(int r,int c,int poured,vector<vector<double>> &dp){
        if(r<0 || c<0 || c>r){
            return 0;
        }
        if(r==0 && c==0){
            return poured;
        }

        if(dp[r][c]!=-1){
            return dp[r][c];
        }
        double left=solve(r-1,c-1,poured,dp);
        double right=solve(r-1,c,poured,dp);

        double leftAmt=max(0.0,(left-1)/2.0);
        double rightAmt=max(0.0,(right-1)/2.0);

        return dp[r][c]=leftAmt+rightAmt;
    }
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> dp(query_row+1,vector<double>(query_row+1,-1));
        return min(1.0,solve(query_row,query_glass,poured,dp));
    }
};