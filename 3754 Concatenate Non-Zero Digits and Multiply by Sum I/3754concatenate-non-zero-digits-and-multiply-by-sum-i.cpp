class Solution {
public:
    long long sumAndMultiply(int n) {
        long long rx=0;
        while(n!=0){
            int r=n%10;
            if(r!=0){
                rx=rx*10+r;
            }
            n/=10;
        }
        long long x=0;
        long long sum=0;
        while(rx!=0){
            int r=rx%10;
            x=x*10+r;
            rx/=10;
            sum+=r;
        }
        return x*sum;
    }
};