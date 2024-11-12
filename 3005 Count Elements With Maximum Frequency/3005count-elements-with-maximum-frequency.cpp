class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> mp;
        int c=0;
        for(auto t:nums){
            mp[t]++;
        }
        int m;
        for(auto t:mp){
            m=max(m,t.second);
        }
        for(auto t:mp){
            if (t.second==m){
                c+=m;
            }
        }
        return c;
    }
};