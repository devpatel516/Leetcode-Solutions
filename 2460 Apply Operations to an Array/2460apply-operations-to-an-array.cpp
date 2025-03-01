class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]==nums[i]){
                nums[i-1]=2*nums[i-1];
                nums[i]=0;
            }
        }
        int j=0,c=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                c++;
            }
            else{
                nums[j]=nums[i];
                j++;
            }
        }
        while(c--){
            nums[j]=0;
            j++;
        }
        return nums;
    }
};