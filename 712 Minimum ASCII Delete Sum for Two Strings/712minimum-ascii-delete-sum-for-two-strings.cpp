class Solution {
public:
    int asciisum(string s){
        int ans=0;
        for(auto k:s){
            ans+=(int)k;
        }
        return ans;
    }
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=(int)s1[i-1]+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        int k=dp[n][m];
        cout<<k<<endl;
        int sum1=asciisum(s1);
        int sum2=asciisum(s2);
        return sum1+sum2-2*k;        
    }
};