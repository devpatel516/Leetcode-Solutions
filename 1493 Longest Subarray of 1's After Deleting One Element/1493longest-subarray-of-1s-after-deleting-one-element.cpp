class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int r=0;
        int z=0;
        int c=0;
        int maxi=-1;
        while(r<n){
            if(nums[r]==0){
                z++;
            }
            while(z>1){
                if(nums[l]==0){
                    z--;
                }
                l++;
            }
            maxi=max(maxi,r-l);
            r++;
        }
        return maxi;
    }
};