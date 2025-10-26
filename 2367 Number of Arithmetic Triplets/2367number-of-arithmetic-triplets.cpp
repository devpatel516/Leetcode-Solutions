class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int ans=0;
        unordered_map<int,bool> mp;

        for(auto c:nums){
            mp[c]=true;
        }

        for(auto c:nums){
            if(mp[c-diff] && mp[c+diff]){
                ans++;
            }
        }
        return ans;
    }
};