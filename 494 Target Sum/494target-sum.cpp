class Solution {
public:
    int total=0;
    int func(vector<int>& nums, int target,int sum,int i,vector<vector<int>> &dp){
        if(i==nums.size()){
            if(target==sum){
                return 1;
            }
            return 0;
        }
        if(dp[i][sum+total]!=-1){
            return dp[i][sum+total];
        }
        int sub=func(nums,target,sum-nums[i],i+1,dp);
        int add=func(nums,target,sum+nums[i],i+1,dp);

        return dp[i][sum+total]=add+sub;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        total=accumulate(nums.begin(),nums.end(),0);
        vector<vector<int>> dp(nums.size(),vector<int> (2*total+1,-1));
        return func(nums,target,0,0,dp);
    }
};