class Solution {
public:
    int func(int i,int j,vector<int>& nums1,vector<int>& nums2,vector<vector<int>> &dp){
        if(i<0 || j<0){
            return INT_MIN/2;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int take=nums1[i]*nums2[j];
        take=max(take,nums1[i]*nums2[j]+func(i-1,j-1,nums1,nums2,dp));
        int case2=func(i,j-1,nums1,nums2,dp);
        int case3=func(i-1,j,nums1,nums2,dp);

        return dp[i][j]=max(take,max(case2,case3));
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return func(nums1.size()-1,nums2.size()-1,nums1,nums2,dp);
    }
};