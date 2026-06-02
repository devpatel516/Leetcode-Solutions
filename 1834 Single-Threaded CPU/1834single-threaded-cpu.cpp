class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,
        greater<pair<int,int>>> pq;
        vector<int> res;
        int n=tasks.size();
        for(int i=0;i<n;i++){
            tasks[i].push_back(i);
        }
        sort(tasks.begin(),tasks.end());
        int i=0;
        long long t=tasks[0][0];

        while(!pq.empty() || i<n){
            while(i<n && t>=tasks[i][0]){
                pq.push({tasks[i][1],tasks[i][2]});
                i++;
            }

            if(!pq.empty()){
                t+=pq.top().first;
                res.push_back(pq.top().second);
                pq.pop();
            }
            else{
                t=tasks[i][0];
            }
        }
        return res;
    }
};