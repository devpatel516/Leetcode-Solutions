class Solution {
public:
    int findMaxVal(int n, vector<vector<int>>& restrictions, vector<int>& diff) {
        int maxVal=1e6;
        vector<int> temp(n,maxVal);
        temp[0]=0;
        for(auto k:restrictions){
            temp[k[0]]=min(temp[k[0]],k[1]);
        }

        for(int i=1;i<n;i++){
            temp[i]=min(temp[i],temp[i-1]+diff[i-1]);
        }

        for(int i=n-2;i>=0;i--){
            temp[i]=min(temp[i],temp[i+1]+diff[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,temp[i]);
        }
        return ans;
    }
};