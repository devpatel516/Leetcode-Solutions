class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        long long sum=0;
        set<vector<int>> s;
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        // if(target==-294967296){
        //     return {};
        // }
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                int left=j+1;
                int right=nums.size()-1;

                while(left<right){
                    sum=(long long)nums[i]+nums[j]+nums[left]+nums[right];
                    if(sum==target){
                        s.insert({nums[i],nums[j],nums[left],nums[right]});
                        left++;
                        right--;
                    }
                    else if(sum<target){
                        left++;
                    }
                    else{
                        right--;
                    }
                }
            }
        }
        for(auto t:s){
            res.push_back(t);
        }
        return res;
    }
};