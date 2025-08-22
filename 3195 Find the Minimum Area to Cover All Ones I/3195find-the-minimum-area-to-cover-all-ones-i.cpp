class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        int minR=m;
        int minC=n;
        int maxR=-1;
        int maxC=-1;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    minR=min(minR,i);
                    minC=min(minC,j);
                    maxR=max(maxR,i);
                    maxC=max(maxC,j);
                }
            }
        }
        return (maxR-minR+1)*(maxC-minC+1);
    }
};