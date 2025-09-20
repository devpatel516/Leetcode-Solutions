class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int n=intervals.size();
        if(n==0){
            return {newInterval};
        }
        int i=0;
        while(i<n && intervals[i][1]<newInterval[0]){
            ans.push_back(intervals[i]);
            i++;
        }
        int a=newInterval[0],b=newInterval[1];
        while(i<n && intervals[i][0]<=b){
            a=min(a,intervals[i][0]);
            b=max(b,intervals[i][1]);
            i++;
        }
        // if(i==n){
        //     ans.push_back(newInterval);
        //     return ans;
        // }
        ans.push_back({a,b});
        while(i<n){
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};