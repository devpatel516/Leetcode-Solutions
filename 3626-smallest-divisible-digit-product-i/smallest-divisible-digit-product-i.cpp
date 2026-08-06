class Solution {
public:
    int digitProduct(int n){
        int k=1;
        while(n!=0){
            int r=n%10;
            k*=r;
            n/=10;
        }
        return k;
    }
    int smallestNumber(int n, int t) {
        int ans=0;
        for(int i=n;i<=100;i++){
            int dProd=digitProduct(i);
            if(dProd%t==0){
                ans=i;
                break;
            }
        }
        return ans;
    }
};