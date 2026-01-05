class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long absSum=0;
        int negC=0;
        int se=INT_MAX;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix.size();j++){
                if(matrix[i][j]<0){
                    negC++;
                }
                se=min(se,abs(matrix[i][j]));
                absSum+=abs(matrix[i][j]);
            }
        }
        cout<<se<<endl;
        if(negC%2==0){
            return absSum;
        }
        else{
            return absSum-2*se;
        }
    }
};