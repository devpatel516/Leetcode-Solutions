class Solution {
public:
    bool isValid(string s){
        if (s.size() > 3) return false;          
        if (s.size() > 1 && s[0] == '0') return false; 
        int num = 0;
        for (char c : s) {
            if (!isdigit(c)) return false;
            num = num * 10 + (c - '0');
        }
        return num >= 0 && num <= 255;
    }
    void func(string temp,string s,vector<string> &res,int parts){
        if(s.size()==0 && parts==4){
            temp.pop_back();
            res.push_back(temp);
            return ;
        }
        if(parts>=4){
            return ;
        }
        for(int i=0;i<s.size();i++){
            string t=s.substr(0,i+1);
            if(isValid(t)){
                func(temp+t+".",s.substr(i+1),res,parts+1);
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string temp="";
        func(temp,s,res,0);
        return res;
    }
};