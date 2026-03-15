class Solution {
public:
    long long countCommas(long long n) {
        long long ans=0;
        long long c=1,st=1000;
        while(st<=n){
            long long end=st*1000-1;
            long long totalNum=min(n,end)-st+1;
            ans+=c*totalNum;
            c++;
            st*=1000;
        }
        return ans;
    }
};