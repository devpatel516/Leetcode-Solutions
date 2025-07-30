class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0;
        int r=nums.size()-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(mid<r && nums[mid]>nums[mid+1]){
                return nums[mid+1];
            }
            if(mid>0 && nums[mid]<nums[mid-1]){
                return nums[mid];
            }
            
            if(nums[r]>nums[mid]){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return nums[0];
    }
};