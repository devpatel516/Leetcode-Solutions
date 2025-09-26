class Solution {
public:
    int dr[4]={-1,1,0,0};
    int dc[4]={0,0,-1,1};
    void dfs(int i,int j,vector<vector<int>> &vis,vector<vector<char>>& mat){
        int n=mat.size();
        int m=mat[0].size();
        vis[i][j]=1;
        for(int k=0;k<4;k++){
            int nr=i+dr[k];
            int nc=j+dc[k];
            if(nr>=0 && nr<n && nc>=0 && nc<m){
                if(!vis[nr][nc] && mat[nr][nc]=='O'){
                    dfs(nr,nc,vis,mat);
                }
            }
        }
    };
    void solve(vector<vector<char>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));

        for(int i=0;i<n;i++){
            if(!vis[i][0] && mat[i][0]=='O'){
                dfs(i,0,vis,mat);
            }
            if(!vis[i][m-1] && mat[i][m-1]=='O'){
                dfs(i,m-1,vis,mat);
            }
        }

        for(int j=0;j<m;j++){
            if(!vis[0][j] && mat[0][j]=='O'){
                dfs(0,j,vis,mat);
            }
            if(!vis[n-1][j] && mat[n-1][j]=='O'){
                dfs(n-1,j,vis,mat);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && mat[i][j]=='O'){
                    mat[i][j]='X';
                }
            }
        }
    }
};