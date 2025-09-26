class Solution {
private:
    int dr[4]={-1,1,0,0};
    int dc[4]={0,0,-1,1};
    void bfs(int i,int j,vector<vector<int>>& vis,vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        q.push({i,j});
        vis[i][j]=1;
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int nr=r+dr[k];
                int nc=c+dc[k];
                if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && grid[nr][nc]==1){
                    vis[nr][nc]=1;
                    q.push({nr,nc});     
                }
            }
        }
    };
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));

        for(int i=0;i<m;i++){
            if(grid[0][i]==1 && !vis[0][i]){
                bfs(0,i,vis,grid);
            }

            if(grid[n-1][i]==1 && !vis[n-1][i]){
                bfs(n-1,i,vis,grid);
            }
        }

        for(int j=0;j<n;j++){
            if(grid[j][0]==1 && !vis[j][0]){
                bfs(j,0,vis,grid);
            }

            if(grid[j][m-1]==1 && !vis[j][m-1]){
                bfs(j,m-1,vis,grid);
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    ans++;
                }
            }
        }
        return ans;
    }
};