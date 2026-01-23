class Solution {
public:
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    void dfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& vis,set<pair<int,int>> &island){
        island.insert({i,j});
        vis[i][j]=1;
        int n=grid.size();
        int m=grid[0].size();
        for(int k=0;k<4;k++){
            int nx=i+dx[k];
            int ny=j+dy[k];
            if(nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny] && grid[nx][ny]==1){
                dfs(nx,ny,grid,vis,island);
            }
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));
        set<pair<int,int>> isl1,isl2;
        bool first=true;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    if(first){
                        dfs(i,j,grid,vis,isl1);
                        first=false;
                    }
                    else{
                        dfs(i,j,grid,vis,isl2);
                    }
                }
            }
        }
        cout<<isl1.size()<<" "<<isl2.size()<<endl;
        int ans=INT_MAX;
        for(auto [x1,y1]:isl1){
            for(auto [x2,y2]:isl2){
                ans=min(ans,abs(x1-x2)+abs(y1-y2)-1);
            }
        }
        return ans;
    }
};