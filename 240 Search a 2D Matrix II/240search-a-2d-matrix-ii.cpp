class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=0;
        int c=matrix[0].size()-1;
        while(r<matrix.size() && c>=0){
            int cur=matrix[r][c];
            if(cur==target){
                return true;
            }
            else if(cur>target){
                c--;
            }
            else{
                r++;
            }
        }
        return false;
    }
};