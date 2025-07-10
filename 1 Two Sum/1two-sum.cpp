class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
          vector<pair<int,int>> temp;
          for(int i=0;i<nums.size();i++){
            temp.push_back({nums[i],i});
          }
          sort(temp.begin(),temp.end());
          vector<int> ans(2);
          int l=0;
          int r=nums.size()-1;
          while(l<=r){
            if(temp[l].first+temp[r].first==target){
                ans[0]=temp[l].second;
                ans[1]=temp[r].second;
                return ans;
            }
            else if(temp[l].first+temp[r].first<target){
                l++;
            }
            else{
                r--;
            }
          }
          return ans;
    }
};