class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size(),r=n-1,c=0,ans=0;
        while(r>=0 && c<m){
            if(grid[r][c]<0){
                ans+=m-c;
                r--;
            }
            else{
                c++;
            }
        }
        return ans;
    }
};