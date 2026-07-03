class Solution {
public:
    int solve(int i,vector<int>& nums,vector<int> &dp){
        if(i==0){
            return nums[i];
        }
        if(i<0){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int rob=nums[i]+solve(i-2,nums,dp);
        int notRob=0+solve(i-1,nums,dp);

        return dp[i]=max(rob,notRob);
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        vector<int> zeroTo=nums;
        zeroTo.pop_back();
        vector<int> oneTo=nums;
        oneTo.erase(oneTo.begin());
        vector<int> dp1(zeroTo.size(), -1);
        vector<int> dp2(oneTo.size(), -1);
        int a=solve(zeroTo.size()-1,zeroTo,dp1);
        int b=solve(oneTo.size()-1,oneTo,dp2);
        return max(a,b);
    }
};
