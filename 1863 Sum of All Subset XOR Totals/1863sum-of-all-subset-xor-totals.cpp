class Solution {
public:
    int ans=0;
    void solve(int i,vector<int>& nums,int &currXor){
        if(i==nums.size()){
            ans+=currXor;
            return ;
        }

        solve(i+1,nums,currXor);

        currXor^=nums[i];
        solve(i+1,nums,currXor);
        currXor^=nums[i];
    }
    int subsetXORSum(vector<int>& nums) {
        int currXor=0;
        solve(0,nums,currXor);
        return ans;
    }
};