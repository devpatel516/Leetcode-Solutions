class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long i,j,k,val=0,m=0;
        for(i=0;i<nums.size();i++){
            for(j=i+1;j<nums.size();j++){
                for(k=j+1;k<nums.size();k++){
                    long long val=(long long)(nums[i]-nums[j])*nums[k];
                    m=max(m,val);
                }
            }
        }
        return m;
    }
};