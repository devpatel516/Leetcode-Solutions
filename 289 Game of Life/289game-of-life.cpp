class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<int> dx = {-1, -1, -1, 0, 0, 1, 1, 1};
        vector<int> dy = {-1, 0, 1, -1, 1, -1, 0, 1};
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int c=0;
                for(int k=0;k<8;k++){
                    int x=i+dx[k];
                    int y=j+dy[k];
                    if(x>=0 && y>=0 && x<m && y<n && (board[x][y]==1 || board[x][y]==3)){
                        c++;
                    }
                }
                if(board[i][j]==1 && (c<2 || c>3)){
                    board[i][j]=3;
                }else if(board[i][j]==0 && c==3){
                    board[i][j]=4;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==3){
                    board[i][j]=0;
                }
                else if(board[i][j]==4){
                    board[i][j]=1;
                }
            }
        }
    }
};