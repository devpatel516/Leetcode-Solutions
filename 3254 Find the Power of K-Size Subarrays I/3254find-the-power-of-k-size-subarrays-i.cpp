class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        if(k==1){
            return nums;
        }
        int j=0;
        int n=nums.size();
        vector<int> res;
        bool v=true;
        for(int r=1;r<k;r++){
            if(nums[r]-nums[r-1]==1){
                j++;
            }
            else{
                j=k-1;
                v=false;
                break;
            }
        }
        if(v){
            res.push_back(nums[j]);
        }
        else{
            res.push_back(-1);
        }
        while(j<n-1){
            j++;
            if(nums[j]-nums[j-1]==1 && v){
                res.push_back(nums[j]);
            }
            else{
                v=true;
                for(int x=j-k+1;x<j;x++){
                    if(nums[x+1]-nums[x]!=1){
                        v=false;
                        break;
                    }
                }
                if(v){
                    res.push_back(nums[j]);
                }
                else{
                    res.push_back(-1);
                }
            }
        }
        return res;
    }
};