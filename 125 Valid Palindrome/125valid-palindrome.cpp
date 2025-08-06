class Solution {
public:
    bool func(string &s,int i){
        if(i>=s.size()/2){
            return true;
        }
        if(s[i]!=s[s.size()-i-1]){
            return false;
        }
        return func(s,i+1);
    }
    bool isPalindrome(string s) {
        string sn="";
        for(auto c:s){
            if(!isalnum(c)){
                continue;
            }
            sn+=tolower(c);
        }
        return func(sn,0);
    }
};