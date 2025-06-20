class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int,int> m;
        for(auto k:nums){
            m[k]++;
        }
        vector<int> ans;
        for(auto c:m){
            if(c.second==2){
                ans.push_back(c.first);
            }
        }
        return ans;
    }
};