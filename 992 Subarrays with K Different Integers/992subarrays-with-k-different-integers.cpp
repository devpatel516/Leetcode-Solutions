class Solution {
public:
    int helper(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int l = 0;
        int r = 0;
        int ans = 0;
        int distinct = 0;
        int n = nums.size();
        while (r < n) {
            if (mp[nums[r]]==0) {
                distinct++;
            }
            mp[nums[r]]++;
            while (distinct > k) {
                mp[nums[l]]--;
                if (mp[nums[l]] == 0) {
                    distinct--;
                }
                l++;
            }
            ans += (r - l + 1);
            r++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return helper(nums, k) - helper(nums, k - 1);
    }
};