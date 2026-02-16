class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> mp;
        for(auto it:answers){
            mp[it]++;
        }
        int ans=0;
        for(auto it:mp){
            int t=it.first+1;
            int count=it.second;
            if(count%t==0){
                ans+=t*(count/t);
            }else{
                ans+=t*((count/t)+1);
            }
        }
        return ans;
    }
};