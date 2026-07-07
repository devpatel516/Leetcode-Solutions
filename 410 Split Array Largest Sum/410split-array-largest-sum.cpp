class Solution {
public:
    int partitions(vector<int>& nums,int sum){
        int partition=1;
        int cs=0;
        for(int i=0;i<nums.size();i++){
            if(cs+nums[i]<=sum){
                cs+=nums[i];
            }else{
                partition++;
                cs=nums[i];
            }
        }
        return partition;
    }
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);

        while(low<=high){
            int mid=(low+high)/2;
            int partition=partitions(nums,mid);
            if(partition>k){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return low;
    }
};