class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        set<int> odd,even;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            even.clear();
            odd.clear();
            for(int j=i;j<nums.size();j++){
                if(nums[j]%2==0){
                    even.insert(nums[j]);
                }
                else{
                    odd.insert(nums[j]);
                }

                if(odd.size()==even.size()){
                    ans=max(ans,j-i+1);
                }
            }
        }
        return ans;
    }
};