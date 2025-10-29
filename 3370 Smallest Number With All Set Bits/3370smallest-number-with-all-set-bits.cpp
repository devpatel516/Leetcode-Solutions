class Solution {
public:
    int smallestNumber(int n) {
        for(int i=1;i<=n;i++){
            if(pow(2,i)>n){
                return pow(2,i)-1;
            }
        }
        return 0;
    }
};