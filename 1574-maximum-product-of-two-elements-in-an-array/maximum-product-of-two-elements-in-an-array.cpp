class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int fl=INT_MIN,fi=0;
        int sl=INT_MIN,si=0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]>fl){
                fl=nums[i];
                fi=i;
            }
        }
        nums[fi]=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>sl){
                sl=nums[i];
                si=i;
            }
        }
        return (fl-1)*(sl-1);
    }
};