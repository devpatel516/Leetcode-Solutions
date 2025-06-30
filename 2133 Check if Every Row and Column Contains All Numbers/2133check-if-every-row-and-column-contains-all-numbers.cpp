class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n=matrix.size();
        unordered_set<int> row[n];
        unordered_set<int> col[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                row[i].insert(matrix[i][j]);
                col[j].insert(matrix[i][j]);
            }
        }
        for(int i=0;i<n;i++){
            if(row[i].size()!=n){
                return false;
            }
            if(col[i].size()!=n){
                return false;
            }
        }
        return true;
    }
};