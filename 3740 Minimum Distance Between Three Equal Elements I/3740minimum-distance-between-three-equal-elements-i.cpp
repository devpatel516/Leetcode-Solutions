class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        if(nums.size()<3){
            return -1;
        }
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }
        int mini=INT_MAX;
        for(auto k:mp){
            if(k.second.size()>=3){
                vector<int> temp=k.second;
                for(int i=0;i<temp.size();i++){
                    for(int j=i+1;j<temp.size();j++){
                        for(int k=j+1;k<temp.size();k++){
                            int x=abs(temp[i]-temp[j])+abs(temp[j]-temp[k])+abs(temp[k]-temp[i]);
                            mini=min(mini,x);
                        }
                    }
                }
                cout<<mini<<endl;
            }
        }
        return mini==INT_MAX?-1:mini;
    }
};