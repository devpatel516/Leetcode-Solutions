class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        int n=nums.size();
        int ans=0;
        for(int l=0;l<n;l++){
            int totalTarget=0;
            for(int r=l;r<n;r++){
                if(nums[r]==target){
                    totalTarget++;
                }

                int length=r-l+1;
                if(totalTarget>length/2){
                    ans++;
                }
            }
        }
        return ans;
    }
};