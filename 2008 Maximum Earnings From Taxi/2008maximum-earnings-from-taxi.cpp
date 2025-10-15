class Solution {
public:
    long long func(int i,vector<vector<int>>& rides,vector<int> &start,vector<long long> &dp){
        if(i==rides.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        long long nottake=0+func(i+1,rides,start,dp);
        long long profit=rides[i][1]-rides[i][0]+rides[i][2];
        long long nextInd=lower_bound(start.begin(),start.end(),rides[i][1])-start.begin();
        long long take=profit+func(nextInd,rides,start,dp);

        return dp[i]=max(take,nottake);
    }
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        vector<int> start(rides.size());
        vector<long long> dp(rides.size(),-1);
        sort(rides.begin(),rides.end());

        for(int i=0;i<rides.size();i++){
            start[i]=rides[i][0];
        }
        return func(0,rides,start,dp);
    }
};