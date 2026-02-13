class Solution {
public:
    int countHomogenous(string s) {
        long long c=1;
        long long ans=0;
        int n=s.size();
        int mod=1e9+7;
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]){
                c++;
            }
            else{
                cout<<c<<endl;
                ans+=(c*(c+1))/2;
                c=1;
            }
        }
        ans+=(c*(c+1))/2;
        return ans%mod;
    }
};