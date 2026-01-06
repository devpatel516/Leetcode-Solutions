class Solution {
public:
    int maxVowels(string s, int k) {
        int ans=INT_MIN;
        int c=0;    
        int n=s.size();
        for(int i=0;i<k;i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
                c++;
                ans=max(ans,c);
            }
        }
        int r=k;
        int l=0;
        while(r<n){
            if(s[r]=='a' || s[r]=='e' || s[r]=='i' || s[r]=='o' || s[r]=='u'){
                c++;
            }
            if(s[l]=='a' || s[l]=='e' || s[l]=='i' || s[l]=='o' || s[l]=='u'){
                c--;
            }
            ans=max(ans,c);
            r++;
            l++;
        }
        return ans;
    }
};