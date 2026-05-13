class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int n=logs.size();
        vector<pair<int,int>> a;
        for(int i=0;i<n;i++){
            a.push_back({logs[i][0],1});
            a.push_back({logs[i][1],-1});
        }
        sort(a.begin(),a.end());
        int curr=0;
        int maxi=0;
        int ans=0;
        for(int i=0;i<a.size();i++){
            curr+=a[i].second;
            if(curr>maxi){
                maxi=curr;
                ans=a[i].first;
            }
        }
        return ans;
    }
};