class Solution {
public:
    const long long MOD = 1000000007;
    long long pow(long long x,long long n){
        if(n==0){
            return 1;
        }
        long long half=pow(x,n/2);
        if(n%2==0){
            return (half*half)%MOD;
        }
        return (x*half*half)%MOD;
    }
    int countGoodNumbers(long long n) {
        long long even=0,odd=0;
        if(n%2==0){
            even=n/2;
            odd=n/2;
        }else{
            even=(n/2)+1;
            odd=n/2;
        }

        int ans=pow(5,even)*pow(4,odd)%MOD;
        return ans;
    }
};