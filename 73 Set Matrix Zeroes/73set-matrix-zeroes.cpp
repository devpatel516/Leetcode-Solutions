class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
       int m=matrix.size();
       int n=matrix[0].size();
       set<int> r;
       set<int> c;
       for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    r.insert(i);
                    c.insert(j);
                }
            }
       } 
       for(auto i:r){
        for(int j=0;j<n;j++){
            matrix[i][j]=0;
        }
       }
       for(auto i:c){
        for(int j=0;j<m;j++){
            matrix[j][i]=0;
        }
       }
    }
};