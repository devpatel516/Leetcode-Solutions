class Solution {
public:
    int longestContinuousSubstring(string s) {
        int n=s.size();
        int ans=1;
        int res=INT_MIN;
        for(int i=1;i<n;i++){
            if(s[i]-s[i-1]==1){
                ans++;
                res=max(res,ans);
            }
            else{
                ans=1;
            }
        }
        return max(res,ans);
    }
};