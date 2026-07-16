class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp1;
        unordered_map<int,int> mp2;

        for(int i=0;i<nums1.size();i++){
            mp1[nums1[i]]++;
        }
        for(int i=0;i<nums2.size();i++){
            mp2[nums2[i]]++;
        }

        vector<vector<int>> ans;
        set<int> temp;
        for(int i=0;i<nums1.size();i++){
            if(mp2.contains(nums1[i])){
                continue;
            }else{
                temp.insert(nums1[i]);
            }
        }
        ans.push_back(vector<int>(temp.begin(),temp.end()));
        temp.clear();
        for(int i=0;i<nums2.size();i++){
            if(mp1.contains(nums2[i])){
                continue;
            }else{
                temp.insert(nums2[i]);
            }
        }
        ans.push_back(vector<int>(temp.begin(),temp.end()));
        return ans;
    }
};