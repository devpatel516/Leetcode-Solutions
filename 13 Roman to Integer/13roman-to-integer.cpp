class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> m;
        m['I']=1;
        m['V']=5;
        m['X']=10;
        m['L']=50;
        m['C']=100;
        m['D']=500;
        m['M']=1000;
        long long ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='.'){
                continue;
            }
            if(s[i]=='I'){
                if(s[i+1]=='V'){
                    ans+=4;
                    s[i+1]='.';
                }
                else if(s[i+1]=='X'){
                    ans+=9;
                    s[i+1]='.';
                }
                else{
                    ans+=1;
                }
            }
            if(s[i]=='X'){
                if(s[i+1]=='L'){
                    ans+=40;
                    s[i+1]='.';
                }
                else if(s[i+1]=='C'){
                    ans+=90;
                    s[i+1]='.';
                }
                else{
                    ans+=10;
                }
            }
            if(s[i]=='C'){
                if(s[i+1]=='D'){
                    ans+=400;
                    s[i+1]='.';
                }
                else if(s[i+1]=='M'){
                    ans+=900;
                    s[i+1]='.';
                }
                else{
                    ans+=100;
                }
            }
            if(s[i]!='I' && s[i]!='X' && s[i]!='C'){
                if(m.find(s[i])!=m.end()){
                    ans+=m[s[i]];
                }
            }
        }
        return ans;
    }
};