class Solution {
public:
    long long splitArray(vector<int>& nums) {
        long long ans=LLONG_MAX;
        int n=nums.size();
        if(n<2){
            return -1;
        }

        vector<long long> prefix(n,0);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+nums[i];
        }

        vector<long long> suffix(n,0);
        suffix[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            suffix[i]=suffix[i+1]+nums[i];
        }

        vector<bool> inc(n,false);
        vector<bool> dec(n,false);

        inc[0]=true;
        for(int i=1;i<n;i++){
            inc[i]=inc[i-1]&&(nums[i]>nums[i-1]);
        }

        dec[n-1]=true;
        for(int i=n-2;i>=0;i--){
            dec[i]=dec[i+1]&&(nums[i]>nums[i+1]);
        }
        for(int i=0;i<n-1;i++){
            if(inc[i] && dec[i+1]){
                long long lmax=prefix[i];
                long long rmax=suffix[i+1];
                ans=min(ans,llabs(lmax-rmax));
            }
        }
        if(ans==LLONG_MAX){
            return -1;
        }
        return ans;
    }
};