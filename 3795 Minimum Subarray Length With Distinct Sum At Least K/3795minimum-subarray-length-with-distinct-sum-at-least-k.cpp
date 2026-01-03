class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n=nums.size();
        int l=0;
        int sum=0;
        int ans=INT_MAX;
        for(int r=0;r<n;r++){
            if(mp[nums[r]]==0){
                sum+=nums[r];
            }
            mp[nums[r]]++;
            while(sum>=k){
                ans=min(ans,r-l+1);
                mp[nums[l]]--;
                if(mp[nums[l]]==0){
                    sum-=nums[l];
                }
                l++;
            }
        }
        if(ans==INT_MAX){
            return -1;
        }
        return ans;
    }
};