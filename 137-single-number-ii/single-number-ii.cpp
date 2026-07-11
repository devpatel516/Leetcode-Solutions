class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        //0 1 2 3 4 5
        for(int i=1;i<nums.size();i+=3){
            if(nums[i-1]!=nums[i]){
                return nums[i-1];
            }
        }
        return nums[nums.size()-1];
    }
};