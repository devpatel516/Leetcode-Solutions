class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int> pmax(nums.size()),pmin(nums.size());
        pmax[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            pmax[i]=max(pmax[i-1],nums[i]);
        }
        pmin[nums.size()-1]=nums[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--){
            pmin[i]=min(pmin[i+1],nums[i]);
        }
        for(int i=0;i<nums.size();i++){
            if(pmax[i]-pmin[i]<=k){
                return i;
            }
        }
        return -1;
    }
};