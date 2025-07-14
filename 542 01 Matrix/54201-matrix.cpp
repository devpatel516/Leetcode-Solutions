class Solution {
public:
    const int dx[4] = {-1, 0, 1, 0}; 
    const int dy[4] = {0, 1, 0, -1};
    bool isSafe(int x,int y,int m,int n){
        return x>=0 && x<m && y>=0 && y<n;
    } 
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> vis(m,vector<int> (n,0));
        vector<vector<int>> dis(m,vector<int> (n,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            int x=p.first.first;
            int y=p.first.second;
            int d=p.second;
            dis[x][y]=d;
            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(isSafe(nx,ny,m,n) && !vis[nx][ny]){
                    q.push({{nx,ny},d+1});
                    vis[nx][ny]=1;
                }
            }
        }
        return dis;
    }
};