class Solution {
public:
    int mySqrt(int x) {
        long long res;
        long long l=1;
        long long h=x;
        while(l<=h){
            long long mid=(l+h)/2;
            if((mid*mid)<=x){
                res=mid;
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        return res;
    }
};