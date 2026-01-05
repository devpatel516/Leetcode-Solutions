class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<nums.size();i++){
            if(mp.count(nums[i])){
                continue;
            }
            for(int j=1;j*j<=nums[i];j++){
                if(nums[i]%j==0){
                    mp[nums[i]].push_back(j);
                    if(j!=nums[i]/j){
                        mp[nums[i]].push_back(nums[i]/j);
                    }
                }
                if(mp[nums[i]].size()>4){
                    break;
                }
            }
        }
        int ans=0;
        for(auto k:nums){
            if(mp[k].size()==4){
                for(auto x:mp[k]){
                    ans+=x;
                }
            }
        }
        return ans;
    }
};