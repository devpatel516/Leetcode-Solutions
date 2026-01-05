class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(auto k:nums){
            mp[k]++;
        }
        int c=0;
        for(auto x:nums){
            if(mp[x]==0){
                continue;
            }
            int y=k-x;
            if(mp.find(y)==mp.end()){
                continue;
            }
            if(x==y){
                if(mp[x]<2){
                    continue;
                }
                mp[x]-=2;
            }
            else{
                if (mp[y] == 0) continue;
                mp[x]--;
                mp[y]--;
            }
            c++;
        }
        return c;
    }
};