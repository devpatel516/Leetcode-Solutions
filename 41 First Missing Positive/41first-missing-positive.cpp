class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i=0;
        int n=nums.size();
        while(i<n){
            long long ci=(long long)nums[i]-1;
            if(ci>=0 && ci<n && nums[i]!=nums[ci]){
                swap(nums[i],nums[ci]);
            }
            else{
                i++;
            }
        }

        for(int i=0;i<n;i++){
            cout<<nums[i]<<" ";
            if(nums[i]!=i+1){
                return i+1;
            }
        }
        return n+1;
    }
};