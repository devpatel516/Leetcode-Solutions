class Solution {
public:
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    int bfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& vis){
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        q.push({i,j});
        vis[i][j]=1;
        int lm=1;
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;

            q.pop();

            for(int d=0;d<4;d++){
                int nx=x+dx[d];
                int ny=y+dy[d];

                if(nx>=0 && ny>=0 && nx<n && ny<m && !vis[nx][ny] && grid[nx][ny]==1){
                    vis[nx][ny]=1;
                    q.push({nx,ny});
                    lm++;
                }
            }
        }
        return lm;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int ans=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    ans=max(ans,bfs(i,j,grid,vis));
                }
            }
        }
    return ans;
    }
};