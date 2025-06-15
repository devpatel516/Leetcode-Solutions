class Solution {
public:
    int thirdMax(vector<int>& n) {
        set<int> s(n.begin(),n.end());
        vector<int> nums(s.begin(),s.end());
        if(nums.size()<3){
            return *max_element(nums.begin(),nums.end());
        }
        sort(nums.begin(),nums.end());
        return nums[nums.size()-3];
    }
};