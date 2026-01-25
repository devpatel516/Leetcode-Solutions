class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        int n=nums.size();
        int c=0;
        for(int i=n-1;i>0;i--){
            if(nums[i]>nums[i-1]){
                c++;
            }
            else{
                break;
            }
        }
        return n-c-1;
    }
};