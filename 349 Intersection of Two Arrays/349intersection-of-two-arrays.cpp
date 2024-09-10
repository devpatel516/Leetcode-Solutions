class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> a(nums1.begin(),nums1.end());
        set<int> b(nums2.begin(),nums2.end());
        int n;
        vector<int> ans;
        for(auto n:b){
            if(a.count(n)){
                ans.push_back(n);
            }
        }
        return ans;
    }
};