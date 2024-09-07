class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len=nums.size();
        k%=len;
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }
};
//7 6 5 4 3 2 1 
//5 6 7 4 3 2 1 
