class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int pi=0,ni=1;
        vector<int> ans(nums.size(),0);
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                ans[pi]=nums[i];
                pi+=2;
            }
            else if(ni<nums.size()){
                ans[ni]=nums[i];
                ni+=2;
            }
        }
        return ans;
    }
};