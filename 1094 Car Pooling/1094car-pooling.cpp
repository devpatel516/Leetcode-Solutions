class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        std::priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>> pq;
        sort(trips.begin(),trips.end(),[](const auto&a,const auto&b){
            return a[1]<b[1];
        });
        if (trips[0][0] > capacity) return false;
        pq.push({trips[0][2],trips[0][0]});
        capacity-=trips[0][0];
        for(int i=1;i<trips.size();i++){
            while(!pq.empty() && trips[i][1]>=pq.top().first){
                capacity+=pq.top().second;
                pq.pop();
            }
            pq.push({trips[i][2],trips[i][0]});
            capacity-=trips[i][0];
            if(capacity<0){
                return false;
            }
            //pq.push({trips[i][0],trips[i][2]});
            cout<<capacity<<endl;
        }
        cout<<capacity<<endl;
        return true;
    }
};