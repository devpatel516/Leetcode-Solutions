class Solution {
public:
    bool func(int i,int target,vector<int> &arr,vector<vector<int>> &dp){
        if(target==0){
            return 0;
        }
        if(i==0){
            return arr[0]==target;
        }
        if(dp[i][target]!=-1){
            return dp[i][target];
        }
        bool nottake=func(i-1,target,arr,dp);
        bool take=false;
        if(target>=arr[i]){
            take=func(i-1,target-arr[i],arr,dp);
        }
        return dp[i][target]=take||nottake;
    }
    bool subsetSumToK(vector<int> &arr,int sum){
        vector<vector<int>> dp(arr.size(),vector<int>(sum+1,-1));
        return func(arr.size()-1,sum,arr,dp);
    }
    bool canPartition(vector<int>& nums) {
        int totalSum=0;
        for(int i=0;i<nums.size();i++){
            totalSum+=nums[i];
        }

        if(totalSum%2==1){
            return false;
        }

        int target=totalSum/2;

        return subsetSumToK(nums,target);
    }
};