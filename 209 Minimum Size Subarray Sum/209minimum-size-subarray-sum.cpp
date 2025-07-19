class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int r=0;
        int sum=0;
        int c=0;
        int mini=INT_MAX;
        bool modified=false;
        while(l<n){
            if(sum<target){
                if(r<n){
                    sum+=nums[r];
                    r++;
                    c++;
                }
                else{
                    break;
                }
            }
            else if(sum>=target){
                mini=min(mini,c);
                modified=true;
                sum-=nums[l];
                l++;
                c--;
            }
        }
        return modified?mini:0;
    }
};