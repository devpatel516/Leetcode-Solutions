class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        vector<int> temp=intervals[0];
        for(auto k:intervals){
            if(k[0]<=temp[1]){
                temp[1]=max(temp[1],k[1]);
            }
            else{
                ans.push_back(temp);
                temp=k;
            }
        }
        ans.push_back(temp);
        return ans;
    }
};