class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        vector<int> mp(n,-1);
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(nums[prev]%nums[i]==0 || nums[i]%nums[prev]==0){
                    if(dp[prev]+1>dp[i]){
                        dp[i]=dp[prev]+1;
                        mp[i]=prev;
                    }
                }
            }
        }

        int maxLen=0,maxInd=0;
        for(int i=0;i<n;i++){
            //cout<<dp[i]<<" ";
            if(dp[i]>maxLen){
                maxLen=dp[i];
                maxInd=i;
            }
        }
        vector<int> res;
        int curr=maxInd;
        while(curr!=-1){
            res.push_back(nums[curr]);
            curr=mp[curr];
        }
        reverse(res.begin(),res.end());
        return res;
    }
};