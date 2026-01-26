class Solution {
public:
    bool helper(int mid,int p,vector<int>& nums){
        int i=0,c=0;
        while(i<nums.size()-1){
            if(nums[i+1]-nums[i]<=mid){
                c+=1;
                i+=2;
            }
            else{
                i++;
            }
            if(c>=p){
                return true;
            }
        }
        return false;
    }
    int minimizeMax(vector<int>& nums, int p) {
        if(p==0){
            return 0;
        }
        sort(nums.begin(),nums.end());
        int l=0;
        int r=1e9;
        int ans;
        while(l<=r){
            int mid=(l+r)/2;
            if(helper(mid,p,nums)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};