class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> a;
        sort(nums.begin(),nums.end());
        int i=0,left=0,right=nums.size()-1;
        while(left<=right){
            if(nums[left]==target){
                a.push_back(left);
                i++;
            }
            left++;
        }
        return a;
    }
};