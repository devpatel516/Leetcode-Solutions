class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(auto x:arr){
            mp[x]++;
        }
        priority_queue<pair<int,int>> pq;
        for(auto k:mp){
            pq.push({k.second,k.first});
        }
        int ans=0;
        int rem=0;
        int n=arr.size()/2;
        while(!pq.empty()){
            rem+=pq.top().first;
            pq.pop();
            ans++;
            if(rem>=n){
                return ans;
            }
        }
        return ans;
    }
};