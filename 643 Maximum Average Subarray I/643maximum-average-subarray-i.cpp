class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum=0,start=0,end;
        double maxs = -1.0 / 0.0;
        for(end=0;end<nums.size();end++){
            sum+=nums[end];
            if(end-start+1 == k){
                maxs=max(maxs,(double)sum/k);
                sum-=nums[start];
                start++;
            }
        }
        return maxs;
    }
};