class Solution {
public:
    int setbits(int n){
        int c=0;
        while(n>0){
            if((n&1)>0){
                c++;
            }
            n=n>>1;
        }
        return c;
    }
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        for(int i=0;i<n+1;i++){
            ans[i]=setbits(i);
        }
    return ans;
    }
};