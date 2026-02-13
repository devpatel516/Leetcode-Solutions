class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        vector<int> temp;
        for(auto k:nums){
            if(k==0){
                temp.push_back(-1);
            }
            else{
                temp.push_back(1);
            }
        }
        unordered_map<int,int> mp;
        mp[0]=-1;
        int sum=0;
        int ans=0;
        for(int i=0;i<temp.size();i++){
            sum+=temp[i];
            if(mp.find(sum-0)!=mp.end()){
                ans=max(ans,i-mp[sum-0]);
            }
            else{
                mp[sum]=i;
            }
        }
        return ans;
    }
};