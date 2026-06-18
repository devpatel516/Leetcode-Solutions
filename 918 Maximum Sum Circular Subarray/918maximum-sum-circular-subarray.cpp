class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int minSum=0;
        int maxSum=0;
        int mini=INT_MAX;
        int maxi=INT_MIN;
        int totalSum=0;
        for(int i=0;i<nums.size();i++){
            totalSum+=nums[i];
            minSum+=nums[i];
            maxSum+=nums[i];
            mini=min(mini,minSum);
            maxi=max(maxi,maxSum);
            if(minSum>0){
                minSum=0;
            }
            if(maxSum<0){
                maxSum=0;
            }
        }
        if(maxi<0){
            return maxi;
        }
        return max(maxi,totalSum-mini);
    }
};