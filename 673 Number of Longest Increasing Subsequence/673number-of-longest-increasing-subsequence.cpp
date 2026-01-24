class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        vector<int> ways(n,1);
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(nums[prev]<nums[i] && 1+dp[prev]>dp[i]){
                    dp[i]=1+dp[prev];
                    ways[i]=ways[prev];
                }
                else if(nums[prev]<nums[i] && 1+dp[prev]==dp[i]){
                    ways[i]+=ways[prev];
                }
            }
        }   
        for(int i=0;i<n;i++){
            maxi=max(maxi,dp[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++) {
            if(dp[i]==maxi) {
                ans+=ways[i];
            }
        }
        return ans;
    }
};