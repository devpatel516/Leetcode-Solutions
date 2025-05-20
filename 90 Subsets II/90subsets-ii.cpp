class Solution {
public:
    void subset(vector<int> &arr,vector<int> &ans,int i,vector<vector<int>> &allsubsets){
        if(i==arr.size()){
            allsubsets.push_back(ans);
            return;
        }
        ans.push_back(arr[i]);
        subset(arr,ans,i+1,allsubsets);
        ans.pop_back();
        int idx=i+1;
        while(idx<arr.size() && arr[i]==arr[idx]){
            idx++;
        }
        subset(arr,ans,idx,allsubsets);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> ans;
        int i=0;
        sort(nums.begin(),nums.end());
        subset(nums,ans,i,res);
        return res;
    }
};