class Solution {
public:
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    void bfs(int i,int j,vector<vector<int>>& heights,vector<vector<int>>& vis){
        int n=heights.size();
        int m=heights[0].size();
        queue<pair<int,int>> q;
        vis[i][j]=1;
        q.push({i,j});

        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();

            for(int k=0;k<4;k++){
                int nx=x+dx[k];
                int ny=y+dy[k];

                if(nx>=0 && ny>=0 && nx<n && ny<m && heights[nx][ny]>=heights[x][y] && !vis[nx][ny]){
                    vis[nx][ny]=1;
                    q.push({nx,ny});
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>> pacific(n,vector<int> (m,0));
        vector<vector<int>> atlantic(n,vector<int> (m,0));

        for(int i=0;i<n;i++){
            bfs(i,0,heights,pacific);
            bfs(i,m-1,heights,atlantic);
        }

        for(int j=0;j<m;j++){
            bfs(0,j,heights,pacific);
            bfs(n-1,j,heights,atlantic);
        }
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pacific[i][j]==1 && atlantic[i][j]==1){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};