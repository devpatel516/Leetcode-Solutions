class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        set<int> st;
        for(auto x:nums){
            st.insert(x);
        }
        int distinct=st.size();
        int n=nums.size();
        int ans=0;
        int l=0;
        unordered_map<int,int> mp;
        for(int r=0;r<n;r++){
            mp[nums[r]]++;
            while(mp.size()==distinct){
                ans+=n-r;
                mp[nums[l]]--;
                if(mp[nums[l]]==0){
                    mp.erase(nums[l]);
                }
                l++;
            }
        }
        return ans;
    }
};