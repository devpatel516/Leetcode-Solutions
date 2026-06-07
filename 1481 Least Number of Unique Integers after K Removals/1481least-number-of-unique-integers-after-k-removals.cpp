class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        unordered_map<int,int> mp;
        for(auto x:arr){
            mp[x]++;
        } 
        cout<<mp.size()<<endl;
        for(auto k:mp){
            pq.push(k.second);
        }
        cout<<pq.size()<<endl;
        //1 2
        while(k--){
            int temp=pq.top();
            pq.pop();
            temp--;
            if(temp!=0){
                pq.push(temp);
            }
        }
        return pq.size();
    }
};