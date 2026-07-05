class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left=0;
        int right=1;
        int i=0;
        int n=nums.size();
        while(right<n){
            if(nums[left]==nums[right]){
                left++;
                right++;
            }else{
                nums[i]=nums[left];
                i++;
                left++;
                right++;
            }
        }
        nums[i]=nums[left];
        return i+1;
    }
};