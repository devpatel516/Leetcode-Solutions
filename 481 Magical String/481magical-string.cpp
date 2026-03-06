class Solution {
public:
    int magicalString(int n) {
        // if(n==0){
        //     return 0;
        // }
        // if(n>=1 && n<=3){
        //     return 1;
        // }
        int ans=1;
        string s="122";
        char next='1';
        int i=2;
        while(s.size()<n){
            int c=s[i]-'0';
            for(int j=0;j<c && s.size()<n;j++){
                s+=next;
                if(next=='1'){
                    ans++;
                }
            }
            if(next=='1'){
                next='2';
            }
            else if(next=='2'){
                next='1';
            }
            i++;
        }
        cout<<s<<endl;
        return ans;
    }
};