class Solution {
public:
    bool func(string s1,string s2){
        int n=s1.size();
        int m=s2.size();
        bool one=false;
        int i=0,j=0;
        if(n==m){
            return false;
        }
        while(i<n || j<m){
            if(s1[i]==s2[j]){
                i++;
                j++;
            }
            else if(s1[i]!=s2[j] && !one){
                one=true;
                j++;
            }
            else{
                return false;
            }
        }
        return true;
    }
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        vector<int> dp(n,1);
        sort(words.begin(),words.end(),[](auto a,auto b){
            return a.size()<b.size();
        });
        for(auto k:words){
            cout<<k<<" ";
        }
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(func(words[prev],words[i])){
                    if(dp[prev]+1>dp[i]){
                        dp[i]=1+dp[prev];
                    }
                }
            }
        }
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};