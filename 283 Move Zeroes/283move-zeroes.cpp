class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left=0,i=0,n;
        while(left<nums.size()){
            if(nums[left]!=0){
                nums[i]=nums[left];
                i++;
            }
            left++;
        }
            while(i<nums.size()){
                nums[i]=0;
                i++;
            }
    }
};