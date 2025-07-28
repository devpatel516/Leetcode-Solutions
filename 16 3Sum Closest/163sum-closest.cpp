class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int diff=0;
        int mindiff=INT_MAX;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int l=i+1;
            int r=nums.size()-1;
            while(l<r){
                int sum=nums[i]+nums[l]+nums[r];
                diff=abs(target-sum);
                if(diff<mindiff){
                    mindiff=diff;
                    ans=sum;
                }
                if(target==sum){
                    return sum;
                }
                else if(target>sum){
                    l++;
                }
                else if (target<sum){
                    r--;
                }
            }
        }
        return ans;
    }
};