class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        int n=nums.size();
        vector<long long> sum(n);
        vector<long long> product(n);
        sum[0]=nums[0];
        for(int i=1;i<n;i++){
            sum[i]=sum[i-1]+nums[i];
        }
        long long ms=sum[n-1];
        product[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            if(product[i+1]>ms/max(nums[i],1)){
                product[i]=ms+1;
            }
            else{
                product[i]=product[i+1]*nums[i];
            }
        }
        // for(auto x:sum){
        //     cout<<x<<" ";
        // }
        // for(auto x:product){
        //     cout<<x<<" ";
        // }
        for(int i=0;i<n;i++){
            long long ls=(i>0)?sum[i-1]:0;
            long long rp=(i<n-1)?product[i+1]:1;
            if(ls==rp){
                return i;
            }
        }
        return -1;
    }
};