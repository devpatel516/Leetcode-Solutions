class Solution {
public:
    long long fun(vector<int> piles,long long n){
        long long total=0;
        for(long long i=0;i<piles.size();i++){
            total+=ceil((double)piles[i]/(double)n);
        }
        return total;
    }
    long long minEatingSpeed(vector<int>& piles,long long h) {
        sort(piles.begin(),piles.end());
        long long low=1;
        long long high=*max_element(piles.begin(),piles.end());
        long long ans;
        while(low<=high){
            long long mid=(low+high)/2;
            if(fun(piles,mid)<=h){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};