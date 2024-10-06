class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        deque<int> d(nums.size());
        for(int i=0;i<nums.size();i++){
            d.push_back(nums[i]);
        }
        for(int i=1;i<k;i++){
            d.pop_back();
        }
            return d.back();
    }
};