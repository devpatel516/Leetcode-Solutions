class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        int left=0;
        int right=0;
        int ans=INT_MIN;
        unordered_map<int,int> mp;
        while(right<n){
            mp[nums[right]]++;
            while(mp.find(nums[right])!=mp.end() && mp[nums[right]]>k){
                mp[nums[left]]--;
                left++;
            }
            ans=max(ans,right-left+1);
            right++;
        }
        return ans;
    }
};