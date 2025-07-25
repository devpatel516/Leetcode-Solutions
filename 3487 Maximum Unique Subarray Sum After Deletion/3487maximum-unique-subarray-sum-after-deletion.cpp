class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_map<int,int> p;
        unordered_map<int,int> n;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=0){
                p[nums[i]]++;
            }
            else{
                n[nums[i]]++;
            }
        }
        int nmax=INT_MIN,pmax=0;
        for(auto k:p){
            pmax+=k.first;
        }
        for(auto k:n){
            int temp=k.first;
            if(temp>nmax){
                nmax=temp;
            }
        }
        if(p.size()==0){
            return nmax;
        }
        return pmax;
    }
};