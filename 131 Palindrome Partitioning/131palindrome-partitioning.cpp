class Solution {
public:
    bool isPalindrome(string s){
        string r=s;
        reverse(r.begin(),r.end());
        if(r==s){
            return true;
        }
        return false;
    }
    void func(string s,vector<string> &ans,vector<vector<string>> &res){
        if(s.size()==0){
            res.push_back(ans);
            return ;
        }
        for(int i=0;i<s.size();i++){
            if(isPalindrome(s.substr(0,i+1))){
                ans.push_back(s.substr(0,i+1));
                func(s.substr(i+1),ans,res);
                ans.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> ans;
        func(s,ans,res);
        return res;
    }
};