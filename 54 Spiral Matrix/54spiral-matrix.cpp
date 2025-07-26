class Solution {
public:
    void fun(vector<vector<int>>& matrix,int top,int bottom,int left,int right,vector<int> &ans)    {
        if(top>bottom || left>right){
            return;
        }
        for(int i=left;i<=right;i++){
            ans.push_back(matrix[top][i]);
        }
        top++;
        for(int i=top;i<=bottom;i++){
            ans.push_back(matrix[i][right]);
        }
        right--;
        if(top<=bottom){
            for(int i=right;i>=left;i--){
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
        }
        if(left<=right){
            for(int i=bottom;i>=top;i--){
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
        fun(matrix,top,bottom,left,right,ans);
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) { 
        int top=0,bottom=matrix.size()-1;
        int left=0,right=matrix[0].size()-1;
        vector<int> ans;
        fun(matrix,top,bottom,left,right,ans);
        return ans;
    }
};