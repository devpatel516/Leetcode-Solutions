class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        priority_queue<int,vector<int>,greater<int>> pq;
        int i=0;
        int days=1;
        int attend=0;
        while(i<events.size() || !pq.empty()){
            while(i<events.size() && events[i][0]==days){
                pq.push(events[i][1]);
                i++;
            }
            while(!pq.empty() && pq.top()<days){
                pq.pop();
            }
            if(!pq.empty()){
                pq.pop();
                attend++;
            }
            days++;
        }
        return attend;
    }
};