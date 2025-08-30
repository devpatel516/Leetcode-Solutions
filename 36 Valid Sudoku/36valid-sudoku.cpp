class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
      unordered_set<int> row[9];
      unordered_set<int> col[9];
      unordered_set<int> box[3][3];
      for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(board[i][j]=='.'){
                continue;
            }
            int dig=board[i][j];
            if(row[i].count(dig)){
                return false;
            }
            else{
                row[i].insert(dig);
            }

            if(col[j].count(dig)){
                return false;
            }
            else{
                col[j].insert(dig);
            }

            if(box[i/3][j/3].count(dig)){
                return false;
            }
            else{
                box[i/3][j/3].insert(dig);
            }
        }
      }
      return true;  
    }
};