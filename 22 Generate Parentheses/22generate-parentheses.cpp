class Solution {
public:
    void func(string s,int open,int close,vector<string> &ans,int n){
        if(s.size()==2*n){
            ans.push_back(s);
            return ;
        }
        if(open<n){
            func(s+"(",open+1,close,ans,n);
        }
        if(close<open){
            func(s+")",open,close+1,ans,n);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        func("",0,0,ans,n);
        return ans;
    }
};