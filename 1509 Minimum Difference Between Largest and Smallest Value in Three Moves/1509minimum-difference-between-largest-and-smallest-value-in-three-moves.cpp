class Solution {
public:
    int minDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size()-1;
        int a=n-3;
        if(a<0){
            return 0;
        }
        int f=nums[a]-nums[0];
        int b=n-2;
        int s=nums[b]-nums[1];
        int c=3;
        if(c>n){
            return 0;
        }
        int t=nums[n]-nums[c];
        int d=2;
        int u=nums[n-1]-nums[2];

        return min(min(f,s),min(t,u));
    }
};