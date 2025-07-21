class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0;
        int r=0;
        int c=0;
        int p=1;
        if(k<=1){
            return 0;
        }
        while(r<n){
            p*=nums[r];
            while(p>=k){
                p/=nums[l];
                l++;
            }
            c+=(r-l)+1;
            r++;
        }
        return c;
    }
};