class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        vector<int> pre1(n+1);
        vector<int> pre2(n+1);
        pre1[0]=nums[0];
        for(int i=1;i<n;i++){
            pre1[i]=pre1[i-1]+nums[i];
        }
        pre2[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            pre2[i]=pre2[i+1]+nums[i];
        }
        for(int i=0;i<n;i++){
            if(pre1[i]==pre2[i]){
                return i;
            }
        }
        return -1;
    }
};