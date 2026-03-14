class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<long long> prefixGcd(nums.size());
        long long mx=nums[0];
        prefixGcd[0]=gcd(nums[0],mx);
        for(int i=1;i<nums.size();i++){
            if(nums[i]>mx){
                mx=nums[i];
            }
            prefixGcd[i]=gcd(nums[i],mx);
        }
        sort(prefixGcd.begin(),prefixGcd.end());
        for(auto x:prefixGcd){
            cout<<x<<" ";
        }
        long long ans=0;
        int l=0;
        int r=nums.size()-1;
        while(l<r){
            ans+=gcd(prefixGcd[l],prefixGcd[r]);
            l++;
            r--;
        }
        return ans;
    }
};