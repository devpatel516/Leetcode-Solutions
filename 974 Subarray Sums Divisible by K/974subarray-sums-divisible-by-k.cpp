class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        freq[0]=1;
        int sum=0,count=0;
        for (int num : nums) {
            sum += num;
            int mod = ((sum % k) + k) % k;

            count += freq[mod];
            freq[mod]++;
        }
        return count;   
    }
};