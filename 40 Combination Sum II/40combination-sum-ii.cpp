class Solution {
public:
    void cs(vector<int> &arr,int target,int i,vector<int> &comb,vector<vector<int>> &ans){
        int n=arr.size();
        if(target==0){
            ans.push_back(comb);
            return;
        }
        if(i==n || target<0){
            return;
        }
        for (int j = i; j < n; ++j) {
            if (j > i && arr[j] == arr[j - 1]) continue;
            if (arr[j] > target) break;
        comb.push_back(arr[j]);
        cs(arr,target-arr[j],j+1,comb,ans);
        comb.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> comb;
        vector<vector<int>> ans;
        cs(candidates,target,0,comb,ans);
        return ans;
    }
};