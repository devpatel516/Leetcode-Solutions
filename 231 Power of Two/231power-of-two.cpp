class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;
        if(((1LL*n) & (n-1))==0){
            return true;
        }
        return false;
    }
};