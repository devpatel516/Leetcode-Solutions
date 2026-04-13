class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        priority_queue<long long> pq;
        long long i=0;
        for(auto x:happiness){
            pq.push(x);
        }
        long long ans=0;
        while(k--){
            //cout<<pq.top()<<" "<<i<<" "<<pq.top()-i<<endl;
            long long add=pq.top()-i;
            if(add>=0){
                ans+=add;
            }
            i++;
            pq.pop();
        }
        return ans;
    }
};