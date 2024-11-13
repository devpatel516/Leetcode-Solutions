class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto it:nums)
        {
            mp[it]++;
        }
        vector<pair<int,int>>arr;
        for(auto&[first,second]:mp)
        {
            arr.push_back({first,second});
        }
        sort(arr.begin(),arr.end(),[](const pair<int,int>&a ,const pair<int,int>&b){
            if(a.second == b.second)
            {
                return a.first > b.first;
            }
            return a.second<b.second;
        });
        vector<int>ans;
        for(auto &[first,second]:arr)
        {
            while(second > 0)
            {
                ans.push_back(first);
                second--;
            }
        }
        return ans;
    }
};