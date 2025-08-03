class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        bool a=false,b=false,c=true;
        int p=-1,q=-1;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]<nums[i+1]){
                p=i;
                a=true;
            }
            else{
                break;
            }
        }
        if(!a || p==nums.size()-1){
            return false;
        }
        for(int i=p+1;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]){
                q=i;
                b=true;
            }
            else{
                break;
            }
        }
        if(!b || q+1==nums.size()-1){
            return false;
        }
        for(int i=q+1;i<nums.size()-1;i++){
            if(nums[i]<nums[i+1]){
                continue;
            }
            else{
                c=false;
                break;
            }
        }
        if(a&&b&&c&&(p<=q)){
            return true;
        }
        return false;
    }
};