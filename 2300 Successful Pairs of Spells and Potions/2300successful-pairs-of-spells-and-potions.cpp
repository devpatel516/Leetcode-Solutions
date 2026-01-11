class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n=spells.size();
        vector<int> ans;
        sort(potions.begin(),potions.end());
        for(int i=0;i<n;i++){
            int l=0;
            int r=potions.size()-1;
            int idx=-1;
            while(l<=r){
                int mid=l+(r-l)/2;
                if((long long)potions[mid]*spells[i]<success){
                    l=mid+1;
                }
                else{
                    idx=mid;
                    r=mid-1;
                }
            }
            ans.push_back(idx);
        }
        for(int i=0;i<ans.size();i++){
            if(ans[i]==-1){
                ans[i]=0;
            }
            else{
                ans[i]=potions.size()-ans[i];
            }
        }
        return ans;
    }
};