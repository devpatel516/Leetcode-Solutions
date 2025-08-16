class Solution {
public:
    int maximum69Number (int num) {
        int i=1,k=0;
        int cp=num;
        while(num>0){
            int r=num%10;
            if(r==6){
                k=i;
            }
            i++;
            num/=10;
        }
            return cp+3*pow(10,k-1);
    }
};