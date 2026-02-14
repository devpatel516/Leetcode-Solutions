class Solution {
public:
    vector<vector<long long>> dp;
    long long helper(int i,int adj,vector<int> &nums,vector<int> &colors){
        if(i<0){
            return 0;
        }
        if(i==0){
            if(adj==0 || colors[0]!=colors[1]){
                return nums[0];
            }
            else{
                return 0;
            }
        }
        if(dp[i][adj]!=-1){
            return dp[i][adj];
        }
        long long take=0;
        if(adj==0 || colors[i]!=colors[i+1]){    
            take=nums[i]+helper(i-1,1,nums,colors);
        }
        long long notTake=0+helper(i-1,0,nums,colors);
        return dp[i][adj]=max(take,notTake);
    }
    long long rob(vector<int>& nums, vector<int>& colors) {
        int n=nums.size();
        int adj=colors.size();
        int maxi=0;
        for(auto k:colors){
            maxi=max(maxi,k);
        }
        dp.assign(n,vector<long long> (2,-1));
        return helper(nums.size()-1,0,nums,colors);
    }
};