class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mini=*min_element(nums.begin(),nums.end());
        int maxi=*max_element(nums.begin(),nums.end());
        set<int> st;
        for(auto x:nums){
            st.insert(x);
        }
        vector<int> ans;
        for(int i=mini;i<=maxi;i++){
            if(!st.count(i)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};