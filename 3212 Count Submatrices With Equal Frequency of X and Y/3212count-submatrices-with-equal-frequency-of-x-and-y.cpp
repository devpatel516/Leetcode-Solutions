class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        //x x  1 2  0 0
        //x y  2 3  0 1

        //x y .  1 1 1  0 1 1
        //y . .  1 1 1  1 2 2
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> preX(n+1,vector<int> (m+1,0));
        vector<vector<int>> preY(n+1,vector<int> (m+1,0));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(grid[i-1][j-1]=='X'){
                    preX[i][j]=1+preX[i-1][j]+preX[i][j-1]-preX[i-1][j-1];
                }
                else{
                    preX[i][j]=preX[i-1][j]+preX[i][j-1]-preX[i-1][j-1];
                }
            }
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(grid[i-1][j-1]=='Y'){
                    preY[i][j]=1+preY[i-1][j]+preY[i][j-1]-preY[i-1][j-1];
                }
                else{
                    preY[i][j]=preY[i-1][j]+preY[i][j-1]-preY[i-1][j-1];
                }
            }
        }

        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(preX[i][j]==preY[i][j] && preX[i][j]!=0){
                    ans++;
                }
            }
        }
        return ans;
    }
};