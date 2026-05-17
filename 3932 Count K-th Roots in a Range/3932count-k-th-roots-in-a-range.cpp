class Solution {
public:
    __int128 solve(long long mid,int k,long long n){
        __int128 power=1;
        for(int i=0;i<k;i++){
            power*=mid;

            if(power>n){
                break;
            }
        }
        return power;
    }
    long long bs(long long n,int k){
        if(n<0){
            return 0;
        }
        long long low=0;
        long long high=n;
        long long ans=0;
        while(low<=high){
            long long mid=low+(high-low)/2;
            if(solve(mid,k,n)<=n){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans+1;
    }
    int countKthRoots(int l, int r, int k) {
        long long right=bs(r,k);
        long long left=bs((long long)l-1,k);

        return right-left;
    }
};