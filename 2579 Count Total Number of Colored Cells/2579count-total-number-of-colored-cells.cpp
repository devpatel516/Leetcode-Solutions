class Solution {
public:
    long long coloredCells(int n) {
        //(2*4)+(2*2)
        long long c=1;
        for(long long i=2;i<=n;i++){
            c+=(2*i)+(2*(i-2));
        }
        return c;
    }
};