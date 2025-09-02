class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.empty())return 0;
        int left,i=0,c=0;
        left=0;
        while(left<=nums.size()-1){
            if(nums[left]!=val){
                nums[c]=nums[left];
                c++;
            }
            left++;
        }
    return c;
    }
};