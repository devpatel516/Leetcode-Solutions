class Solution {
public:
    void func(int i,int n,vector<int> &temp,vector<int> &nums,vector<vector<int>> &ans){
        if(i==n){
            ans.push_back(temp);
            return ;
        }
        //include
        temp.push_back(nums[i]);
        func(i+1,n,temp,nums,ans);
        temp.pop_back();
        //exclude
        func(i+1,n,temp,nums,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        func(0,nums.size(),temp,nums,ans);
        return ans;
    }
};