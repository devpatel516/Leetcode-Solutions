class Solution {
public:
    int helper(vector<int>& nums, int goal){
        int n=nums.size();
        int l=0;
        int r=0;
        int ans=0;
        int k=0;
        if(goal<0){
            return 0;
        }
        while(r<n){
            k+=nums[r];
            while(k>goal && l<=r){
                k-=nums[l];
                l++;
            }
            ans+=(r-l+1);
            r++;
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return helper(nums,goal)-helper(nums,goal-1);      
    }
};