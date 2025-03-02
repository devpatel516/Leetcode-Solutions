class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1,vector<vector<int>>& nums2){
        map<int,int> m;
        vector<vector<int>> res;
        for(int i=0;i<nums1.size();i++){
            m[nums1[i][0]]=nums1[i][1];
        }
        for(int i=0;i<nums2.size();i++){
            m[nums2[i][0]]+=nums2[i][1];
        }
        for (auto c : m) {
            res.push_back({c.first, c.second});
        }
        return res;
    }
};