class Solution {
public:
    int addDigits(int num) {
        long sum=0,d;
        while(num>9){
            while(num>0){
            d=num%10;
            sum+=d;
            num/=10;
            }
            if(num==0){
                num=sum;
                sum=0;
            }
        }
        return num;
    }
};