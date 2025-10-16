class Solution {
public:
    bool isSafe(vector<string> &board,int row,int col,int n){
        for(int i=0;i<n;i++){
            if(board[row][i]=='Q'){
                return false;
            }
        }

        for(int i=0;i<row;i++){
            if(board[i][col]=='Q'){
                return false;
            }
        }

        int i=row-1;
        int j=col-1;
        while(i>=0 && j>=0){
            if(board[i][j]=='Q'){
                return false;
            }
            i--;
            j--;
        }

        i=row-1;
        j=col+1;

        while(i>=0 && j<n){
            if(board[i][j]=='Q'){
                return false;
            }
            i--;
            j++;
        }
        return true;
    } 
    void nQueen(vector<string> &board,int row,int n,set<vector<string>> &ans){
        if(row==n){
            ans.insert(board);
            return ;
        }
        for(int i=0;i<n;i++){
            if(isSafe(board,row,i,n)){
                board[row][i]='Q';
                nQueen(board,row+1,n,ans);
                board[row][i]='.';
            }
        }
    }
    int totalNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        set<vector<string>> ans;
        int row=0;
        nQueen(board,row,n,ans);
        return ans.size();
    }
};