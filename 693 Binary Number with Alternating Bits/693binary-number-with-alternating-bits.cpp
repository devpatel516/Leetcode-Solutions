class Solution {
public:
    bool hasAlternatingBits(int n) {
        int k=n&1;
        cout<<k<<endl;
        n=n>>1;
        while(n>0){
            // int x=n&1;
            // cout<<x<<endl;
            if(k==(n&1)){
                return false;
            }
            else{
                k=n&1;
                n=n>>1;
            }
        }
        return true;
    }
};