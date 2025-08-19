class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long c=0;
        long long ans=0;
        for(long long i=0;i<nums.size();i++){
            if(nums[i]==0){
                c++;
            }
            else{
                ans+=((c+1)*c)/2;
                c=0;
            }
        }
        return ans+=((c+1)*c)/2;;
    }
};