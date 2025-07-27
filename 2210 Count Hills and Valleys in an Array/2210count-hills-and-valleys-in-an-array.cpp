class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n=nums.size();
        int c=0;
        for(int i=1;i<=n-2;i++){
            if(nums[i]==nums[i-1]){
                continue;
            }
            int nel=-1,ner=-1;
            int j=i-1;
            while(j>=0){
                if(nums[j]!=nums[i]){
                    nel=nums[j];
                    break;
                }
                j--;
            }
            int k=i+1;
            while(k<n){
                if(nums[k]!=nums[i]){
                    ner=nums[k];
                    break;
                }
                k++;
            }
            if(nel>0 && ner>0){
            if((nums[i]>nel && nums[i]>ner) || (nums[i]<nel && nums[i]<ner)){
                c++;
            }
            }
        }
        return c;
    }
};