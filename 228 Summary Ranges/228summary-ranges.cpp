class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int c=0;
        for(int i=0;i<nums.size();i++){
            if(i+1==nums.size() || nums[i]+1!=nums[i+1]){
             if(c==i){
                ans.push_back(to_string(nums[c]));
             }
             else{
                ans.push_back(to_string(nums[c])+"->"+to_string(nums[i]));
             }   
             c=i+1;
            }
        }
        return ans;
    }
};