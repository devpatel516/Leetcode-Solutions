class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> ls(nums.size());
        vector<int> rs(nums.size());

        ls[0]=nums[0];

        for(int i=1;i<nums.size();i++){
            ls[i]=ls[i-1]+nums[i];
        }

        rs[rs.size()-1]=nums[nums.size()-1];

        for(int i=nums.size()-2;i>=0;i--){
            rs[i]=rs[i+1]+nums[i];
        }

        vector<int> res(nums.size());

        for(int i=0;i<nums.size();i++){
            res[i]=abs(ls[i]-rs[i]);
        }
        return res;
    }
};