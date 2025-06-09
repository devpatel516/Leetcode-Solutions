class Solution {
public:
    void bfs(int i,int j,vector<vector<int>> &vis,vector<vector<char>>& grid,int rows,int cols){
        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};
        queue<pair<int,int>> q;
        q.push({i,j});
        vis[i][j]=1;
        while(!q.empty()){
            pair<int,int> k=q.front();
            q.pop();
            for(int m=0;m<4;m++){
                int nr=k.first+dr[m];
                int nc=k.second+dc[m];
                if(nr>=0 && nc>=0 && nr<rows && nc<cols && grid[nr][nc]=='1' && !vis[nr][nc]){
            vis[nr][nc]=1;
            q.push({nr,nc});                
                }
            }        
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        if(rows==0) return 0;
        int cols = grid[0].size();
        vector<vector<int>> vis(rows, vector<int>(cols, 0));
        int c=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    bfs(i,j,vis,grid,rows,cols);
                    c++;
                }
            }
        }
        return c;
    }
};