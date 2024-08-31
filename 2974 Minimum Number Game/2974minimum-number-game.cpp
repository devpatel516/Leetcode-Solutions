class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        vector<int> arr;
        sort(nums.begin(),nums.end());
        int left,right,alice,bob;
        left=0;
        right=nums.size()-1;
        while(left<=right){
            alice=nums[left];
            left++;
            bob=nums[left];
            left++;

            arr.push_back(bob);
            arr.push_back(alice);
        }
        return arr;
    }
};