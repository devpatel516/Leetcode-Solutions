class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto it:nums){
            mp[it]++;
        }
        vector<int> temp;
        for(auto it:mp){
            temp.push_back(it.second);
        }
        unordered_map<int,int> freq;
        for(auto it:mp){
            freq[it.second]++;
        }
        for(int x:nums){
            if(freq[mp[x]]==1){
                return x;
            }
        }
        return -1;
    }
};