class Solution {
public:
    int balancedStringSplit(string s) {
        int cr=0,cl=0;
        int ans=0;
        int j=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='R'){
                cr++;
            }
            else if(s[i]=='L'){
                cl++;
            }
            
            if(cr==cl){
                ans++;
                cl=0;
                cr=0;
            }
            cout<<cl<<" "<<cr<<" "<<ans<<endl;
        }
        return ans;
    }
};