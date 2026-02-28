class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        unordered_map<int,int> mp;
        vector<int> temp;
        for(auto x:nums){
            if(mp.find(x)==mp.end()){
                temp.push_back(x);
            }
            mp[x]++;
        }
        sort(temp.begin(),temp.end());
        //vector<int> ans(2,-1);
        int n=temp.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(mp[temp[i]]!=mp[temp[j]]){
                    return {temp[i],temp[j]};
                }
            }
        }
        return {-1,-1};
    }
};