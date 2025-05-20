class Solution {
public:
    void getpermutations(vector<int> &arr,vector<vector<int>> &ans,int idx){
        if(idx==arr.size()){
            ans.push_back(arr);
            return;
        }
        for(int i=idx;i<arr.size();i++){
            swap(arr[idx],arr[i]);
            getpermutations(arr,ans,idx+1);
            swap(arr[idx],arr[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int idx=0;
        getpermutations(nums,ans,idx);
        return ans;
    }
};