class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        unordered_map<int,int> mp;
        for(auto it:bulbs){
            if(mp.find(it)==mp.end()){
                mp[it]=1;
            }
            else{
                mp[it]=mp[it]-1;
                if(mp[it]==0){
                    mp.erase(it);
                }
            }
        }
        vector<int> res;
        for(auto k:mp){
            if(k.second==1){
               res.push_back(k.first); 
            }
        }
        sort(res.begin(),res.end());
        return res;
    }
};