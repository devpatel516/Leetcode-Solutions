class Solution {
public:
    bool isPalindrome(int x) {
        long long d,sum=0,o=x;
        while(x>0){
            d=x%10;
            x/=10;
            sum=sum*10+d;
        }
        if(x<=-1){
            return false;
        }
        if(sum==o){
            return true;
        }
        return false;
    }
};