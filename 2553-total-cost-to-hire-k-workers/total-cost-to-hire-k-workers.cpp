class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long n=costs.size();
        long long cost=0;
        if(2*candidates>n){
            priority_queue<long long,vector<long long>,greater<long long>> pq;
            for(int i=0;i<n;i++){
                pq.push(costs[i]);
            }
            while(!pq.empty() && k--){
                cost+=pq.top();
                pq.pop();
            }
        }else{
            priority_queue<long long,vector<long long>,greater<long long>> p1,p2;
            long long l=candidates;
            long long r=n-candidates-1;
            for(int i=0;i<candidates;i++){
                p1.push(costs[i]);
            }
            for(int i=n-1;i>=n-candidates;i--){
                p2.push(costs[i]);
            }
            while(k--){
                long long val1 = !p1.empty() ? p1.top() : INT_MAX;
                long long val2 = !p2.empty() ? p2.top() : INT_MAX;
                if(val1<=val2){
                    cost+=p1.top();
                    p1.pop();
                    if(l<=r){
                        p1.push(costs[l]);
                        l++;
                    }
                }else{
                    cost+=p2.top();
                    p2.pop();
                    if(l<=r){
                        p2.push(costs[r]);
                        r--;
                    }
                }
            }
        }
        return cost;
    }
};