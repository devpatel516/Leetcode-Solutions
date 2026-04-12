class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        vector<int> ans;
        for(int i=0;i<matrix.size();i++){
            int c=0;
            for(int j=0;j<matrix.size();j++){
                if(matrix[i][j]==1){
                    c++;
                }
            }
            ans.push_back(c);
        }
        return ans;
    }
};