class Solution {
public:
    bool checkZeroOnes(string s) {
        int o=0;
        int max1=-1;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                o++;
            }
            else{
                o=0;
            }
            max1=max(o,max1);
        }
        int z=0;
        int max0=-1;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){
                z++;
            }
            else{
                z=0;
            }
            max0=max(z,max0);
        }
        return max1>max0;
    }
};