class NumMatrix {
public:
    vector<vector<int>> mat;
    vector<vector<int>> prefix;
    NumMatrix(vector<vector<int>>& matrix) {
        mat=matrix;
        int m=mat.size();
        int n=mat[0].size();
        prefix=vector<vector<int>>(m,vector<int> (n,0));
    for(int i=0;i<m;i++){
      for(int j=0;j<n;j++){
        if(i==0 && j==0){
          prefix[i][j]=mat[i][j];
        }
        if(i==0 && j>0){
          prefix[i][j]=prefix[i][j-1]+mat[i][j];
        }
        if(i>0 && j==0){
          prefix[i][j]=prefix[i-1][j]+mat[i][j];
        }
        if(i>0 && j>0){
          prefix[i][j]=prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1]+mat[i][j];
        }
      }
    }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int a=row1>0?prefix[row1-1][col2]:0;
        int b=col1>0?prefix[row2][col1-1]:0;
        int c=(row1>0 && col1>0)?prefix[row1-1][col1-1]:0;
        return prefix[row2][col2]-(a+b-c);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */