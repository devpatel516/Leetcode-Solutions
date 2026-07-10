class Solution {
public:
    int countSetbits(int num){
        int count=0;
        while(num>0){
            if(num&1){
                count++;
            }
            num>>=1;
        }
        return count;
    }
    int minBitFlips(int start, int goal) {
        //1010 start
        //0111 goal
        //1101
        int temp=start^goal;
        return countSetbits(temp);
    }
};