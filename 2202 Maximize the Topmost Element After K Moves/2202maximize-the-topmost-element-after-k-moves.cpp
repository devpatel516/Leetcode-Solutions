class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int n=nums.size();
        if(k==0){
            return nums[0];
        }
        if(n==1){
            if(k%2==0){
                return nums[0];
            }
            else{
                return -1;
            }
        }
        int maxi=INT_MIN;
        int i=0;
        for(i=0;i<n&&k>1;i++){
            maxi=max(nums[i],maxi);
            k--;
        }
        cout<<i<<" "<<n<<" "<<k<<endl;
        if(i<n && k>=1){
            maxi=max(nums[i+1],maxi);
        }
        return maxi;
    }
};