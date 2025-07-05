class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(auto k:arr){
            mp[k]++;
        }
        int maxi=-1;
        for(auto c:mp){
            if(c.first==c.second){
                maxi=max(maxi,c.first);
            }
        }
        return maxi;
    }
};