class Solution {
public:
    int triangularSum(vector<int>& nums) {
            int i=0;
            while(i<nums.size()-1){
            for(int j=0;j<nums.size()-1;j++){
                nums[j]=(nums[j]+nums[j+1])%10;
            }
            i++;
            }
        return nums[0];
    }
};