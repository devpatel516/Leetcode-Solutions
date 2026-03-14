class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp,m1,m2;
        for(int x:nums1){
            m1[x]++;
            mp[x]++;
        }
        for(int x:nums2){
            m2[x]++;
            mp[x]++;
        }

        for(auto k:mp){
            if(k.second%2==1){
                return -1;
            }
        }
        int c=0;
        for(auto x:mp){
            int k=x.first;
            c+=abs(m1[k]-m2[k])/2;
        }
        return c/2;
    }
};