class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i=0;
        int n=nums.size();

        while(i<n){
            int ci=nums[i];

            if(nums[i]<n && nums[i]!=nums[ci]){
                swap(nums[i],nums[ci]);
            }
            else{
                i++;
            }
        }

        for(int i=0;i<n;i++){
            if(nums[i]!=i){
                return i;
            }
        }
        return n;
    }
};