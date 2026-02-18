class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        long long n=nums1.size();
        vector<pair<long long ,long long>> a(n);
        //1 3
        //2 1
        //3 3
        //4 2

        //queue
        //3 sum=3
        //1 sum=4
        //3 sum=7
        //2 sum=8
        for(long long i=0;i<n;i++){
            a[i].first=nums2[i];
            a[i].second=nums1[i];
        }
        sort(a.rbegin(),a.rend());
        priority_queue<long long,vector<long long>,greater<long long>> pq;
        long long ans=0;
        long long sum=0;
        for(auto it:a){
            sum+=it.second;
            pq.push(it.second);
            if(pq.size()>k){
                long long t=pq.top();
                sum-=t;
                pq.pop();
            }
            if(pq.size()==k){
                ans=max(ans,sum*it.first);
            }   
        }
        return ans;
    }
};