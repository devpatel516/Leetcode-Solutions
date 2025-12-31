class Solution {
public:
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    bool dfs(int row,int col,int i,vector<vector<char>>& board,vector<vector<int>>& vis,string &word){
        if(i==word.size()){
            return true;
        }
        int n=board.size();
        int m=board[0].size();
        vis[row][col]=1;
        for(int k=0;k<4;k++){
            int nr=dx[k]+row;
            int nc=dy[k]+col;
            if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && board[nr][nc]==word[i]){
                if(dfs(nr,nc,i+1,board,vis,word)){
                    return true;
                }
            }
        }
        vis[row][col]=0;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    if(dfs(i,j,1,board,vis,word)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};