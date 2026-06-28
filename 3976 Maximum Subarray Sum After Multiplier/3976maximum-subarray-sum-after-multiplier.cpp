class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        long long a=INT_MIN,b=INT_MIN,c=INT_MIN,d=INT_MIN;
        long long ans=INT_MIN;

        for(auto x:nums){
            long long mul=(long long)x*k;
            long long div=x>=0?x/k:-(-x/k);

            long long nd=max({d+x,b+x,c+x});
            long long nb=max({b+mul,a+mul,mul});
            long long nc=max({c+div,a+div,div});
            long long na=max((long long)x,a+x);

            a=na;
            b=nb;
            c=nc;
            d=nd;
            ans=max({ans,a,b,c,d});
        }
        return ans;
    }
};