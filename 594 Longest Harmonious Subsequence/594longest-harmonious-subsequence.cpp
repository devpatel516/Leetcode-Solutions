class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto c:nums){
            mp[c]++;
        }
        int ans=0;
        for(auto k:nums){
            if(mp.find(k-1)!=mp.end()){
                ans=max(ans,mp[k]+mp[k-1]);
            }
        }
        return ans;
    }
};