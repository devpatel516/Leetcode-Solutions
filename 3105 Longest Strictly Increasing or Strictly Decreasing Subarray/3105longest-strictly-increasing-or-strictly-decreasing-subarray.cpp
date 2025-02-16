class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ins=0,des=0,ai=0,ad=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]<nums[i]){
                ins++;
                ai=max(ai,ins);
            }
            else{
                ins=0;
            }
        }
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]>nums[i]){
                des++;
                ad=max(ad,des);
            }
            else{
                des=0;
            }
        }
        return max(ai+1,ad+1);
    }
};