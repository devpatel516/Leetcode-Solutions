class Solution {
public:
    void func(int i,string temp,string &s,vector<string> &result){
        if(i==s.size()){
            result.push_back(temp);
            return ;
        }
        if(i>s.size()){
            return ;
        }
        if(isalpha(s[i])){
            temp+=tolower(s[i]);
            cout<<temp<<endl;
            func(i+1,temp,s,result);
            temp.pop_back();
            temp+=toupper(s[i]);
            cout<<temp<<endl;
            func(i+1,temp,s,result);
            temp.pop_back();
        }
        else{
            temp+=s[i];
            cout<<temp<<endl;
            func(i+1,temp,s,result);
        }
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> result;
        string temp="";
        func(0,temp,s,result);
        return result;
    }
};