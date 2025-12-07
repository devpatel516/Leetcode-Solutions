class Solution {
public:
    int numSub(string s) {
        long long MOD=1000000007;
        long long ans=0;
        long long c=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){
                ans=(ans+(c*(c+1)/2)%MOD)%MOD;
                c=0;
            }
            else{
                c++;
            }
        }
        ans=(ans+(c*(c+1)/2)%MOD)%MOD;
        return ans;
    }
};