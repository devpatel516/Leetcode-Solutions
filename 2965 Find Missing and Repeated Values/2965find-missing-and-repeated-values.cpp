class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_map<int,int> mp;
        int n=grid.size();
        int m=-1,r=-1;
        for(auto c:grid){
            for(auto x:c){
                mp[x]++;
            }   
        }   
        for(int i=1;i<=n*n;i++){
            if(mp[i]==0){
                m=i;
            }
            if(mp[i]==2){
                r=i;
            }
        }
        return {r,m};
    }
};