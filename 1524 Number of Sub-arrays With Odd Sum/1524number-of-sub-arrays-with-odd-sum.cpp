class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long long sum=0;
        int odd=0;
        int even=0;
        long long ans=0;
        int mod=1e9+7;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            if(sum%2==0){
                even++;
                ans+=odd;
            }
            else{
                odd++;
                ans+=(even+1);
            }
        }
        return ans%mod;
    }
};