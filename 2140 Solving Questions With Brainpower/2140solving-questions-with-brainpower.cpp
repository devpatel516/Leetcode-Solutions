class Solution {
public:
    // long long func(int i,vector<vector<int>>& questions,vector<long long> &dp){
    //     int n=questions.size();
    //     if(i>=n){
    //         return 0;
    //     }
    //     if(dp[i]!=-1){
    //         return dp[i];
    //     }
    //     long long take=questions[i][0]+func(i+questions[i][1]+1,questions,dp);
    //     long long nottake=0+func(i+1,questions,dp);

    //     return dp[i]=max(take,nottake);
    // }
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        vector<long long> dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            long long ind=i+questions[i][1]+1;
            long long take=questions[i][0];
            if(i+questions[i][1]+1<n){
                take+=dp[i+questions[i][1]+1];
            }
            long long nottake=dp[i+1];
            dp[i]=max(take,nottake);
        }
        return dp[0];
    }
};