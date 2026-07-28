class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.size();
        if(n==1){
            return s;
        }
        vector<int> f(26,0);
        for(auto c:s){
            f[c-'a']++;
        }
        for(auto k:f){
            cout<<k<<" ";
        }
        vector<char> temp(n);
        int l=0;
        int r=n-1;
        for(int i=0;i<26;i++){
            while(f[i]!=0){
                if(f[i]>=2){
                    temp[l]=i+'a';
                    temp[r]=i+'a';
                    l++;
                    r--;
                    f[i]-=2;
                }else{
                    break;
                }
            }
        }
        for(int i=0;i<26;i++){
            if(f[i]==1){
                temp[l]=i+'a';
                l++;
                f[i]-=1;
            }
        }
        string ans="";
        for(auto k:temp){
            ans+=k;
        }
        return ans;
    }
};