class Solution {
public:
    void func(int i,int target,vector<int> ans,vector<vector<int>> &res,vector<int>& candidates){
        if(i==candidates.size()){
            if(target==0){
                res.push_back(ans);
                return ;
            }
            return ;
        }
        if(candidates[i]<=target){
            ans.push_back(candidates[i]);
            func(i,target-candidates[i],ans,res,candidates);
            ans.pop_back();
        }
        func(i+1,target,ans,res,candidates);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> ans;
        func(0,target,ans,res,candidates);
        return res;
    }
};