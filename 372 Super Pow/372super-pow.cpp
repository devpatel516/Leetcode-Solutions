class Solution {
public:
    int M=1337; //1337*(1-1/7)*(1-1/191) => ETF Value
    int ETF=1140; 
    long long help(vector<int> &b){
        long long ans=0;
        for(long long i=0;i<b.size();i++){
            ans=(ans*10+b[i])%ETF;
        }
        return ans;
    }
    int binaryExp(long long a,long long b){
        int ans=1;
        while(b>0){
            if(b&1){
                ans=(ans*1LL*a)%M;
            }
            a=(a*1LL*a)%M;
            b>>=1;
        }
        return ans;
    }
    int superPow(int a, vector<int>& b) {
        bool g=true;
        for(int i=0;i<b.size();i++){
            if(b[i]!=0){
                g=false;
                break;
            }
        }
        long long nb=help(b);
        if(!g && nb==0){
            nb=ETF;
        }
        return binaryExp((long long)a,nb);
    }
};