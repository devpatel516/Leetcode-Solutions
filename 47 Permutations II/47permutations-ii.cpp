class Solution {
public:
    void getper(vector<int> &nums,vector<vector<int>> &ans,int idx){
        if(idx==nums.size()){
            ans.push_back(nums);
            return;
        }
        unordered_set<int> used;
        for(int i=idx;i<nums.size();i++){
            if(used.count(nums[i])) {
                continue;
            }
            used.insert(nums[i]);
            swap(nums[idx],nums[i]);
            getper(nums,ans,idx+1);
            swap(nums[idx],nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int idx=0;
        getper(nums,ans,idx);
        return ans;
    }
};