class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        if(n<=8){
            return n;
        }
        int w=n/8;
        int count=0;
        for(int i=1;i<=w;i++){
            count+=i*8;
        }
        int rem=n-w*8;
        count+=rem*(w+1);
        return count;
    }
};