class Solution {
public:
    void func(int i,int k,int n,vector<int> &ans,vector<vector<int>> &res){
        if(k==ans.size()){
            if(n==0){
                res.push_back(ans);
                return ;
            }
        }
        if(i>9){
            return ;
        }
        if(i<=n){
            ans.push_back(i);
            func(i+1,k,n-i,ans,res);
            ans.pop_back();
        }
        func(i+1,k,n,ans,res);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> ans;
        func(1,k,n,ans,res);
        return res;
    }
};