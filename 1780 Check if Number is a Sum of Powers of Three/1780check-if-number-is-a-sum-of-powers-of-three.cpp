class Solution {
public:
    bool checkPowersOfThree(int n) {
        while(n>0){
            int c;
            c=n%3;
            n/=3;
            if(c!=1 && c!=0){
                return false;
            }    
        }
        return true;
    }
};