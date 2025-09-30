class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> rmax(n);
        int lmax=0;
        rmax[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            rmax[i]=max(rmax[i+1],height[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            lmax=max(lmax,height[i]);

            ans+=min(lmax,rmax[i])-height[i];
        }
        return ans;
    }
};