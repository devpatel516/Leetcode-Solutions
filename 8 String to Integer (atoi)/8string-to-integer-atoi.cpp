class Solution {
public:
    int res(string &s,int i,int sign,long long result){
        if(i>=s.size() || !isdigit(s[i])){
            return result*sign;
        }
        result=result*10+(s[i]-'0');
        if(result*sign>=INT_MAX){
            return INT_MAX;
        }
        if(result*sign<=INT_MIN){
            return INT_MIN;
        }
        return res(s,i+1,sign,result);
    }
    int myAtoi(string s) {
        long long result=0;
        int i=0;
        while(i<s.size() && s[i]==' '){
            i++;
        }
        int sign=1;
        if(s[i]=='+' || s[i]=='-'){
            sign=(s[i]=='-')?-1:1;
            i++;
        }
        while(i<s.size() && s[i]=='0'){
            i++;
        }
        return res(s,i,sign,result);
    }
};