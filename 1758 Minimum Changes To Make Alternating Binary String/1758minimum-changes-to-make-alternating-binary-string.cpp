class Solution {
public:
    int minOperations(string s) {
        int a1=0,a2=0;
        string t=s;
        string p=s;
        for(int i=1;i<t.size();i++){
            if(t[i-1]==t[i]){
                if(t[i]=='0'){
                    t[i]='1';
                }
                else if(t[i]=='1'){
                    t[i]='0';
                }
                a1++;
            }
        }
        p[0] = (p[0] == '0') ? '1' : '0';
        a2++;
        for(int i=1;i<p.size();i++){
            if(p[i-1]==p[i]){
                if(p[i]=='0'){
                    p[i]='1';
                }
                else if(p[i]=='1'){
                    p[i]='0';
                }
                a2++;
            }
        }
        // for(int i=p.size()-2;i>=0;i--){
        //     if(p[i]==p[i+1]){
        //         if(p[i]=='0'){
        //             p[i]='1';
        //         }
        //         else if(p[i]=='1'){
        //             p[i]='0';
        //         }
        //         a2++;
        //     }
        // }
        cout<<t<<endl;
        cout<<p<<endl;
        cout<<a1<<" "<<a2<<endl;
        return min(a1,a2);
        //10010100
        //
    }
};