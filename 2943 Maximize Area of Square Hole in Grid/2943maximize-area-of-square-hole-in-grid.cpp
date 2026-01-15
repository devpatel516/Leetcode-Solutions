class Solution {
public:
    int maxConsecutive(vector<int> &a){
        sort(a.begin(),a.end());

        int ans=1,curr=1;

        for(int i=1;i<a.size();i++){
            if(a[i]==a[i-1]+1){
                curr++;
            }
            else{
                curr=1;
            }
            ans=max(ans,curr);
        }
        return ans;
    }
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int mh=maxConsecutive(hBars);
        int mv=maxConsecutive(vBars);

        int side=min(mh+1,mv+1);
        return side*side;
    }
};