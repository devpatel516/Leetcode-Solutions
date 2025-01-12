class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        vector<int> ans;
        int c=0;
        bool left=true;
        for(int i=0;i<grid.size();i++){
            if(left){
                for(int j=0;j<grid[i].size();j++){
                    c++;
                    if(c%2!=0){
                        ans.push_back(grid[i][j]);
                    }    
                }
            }
            else{
                for(int j=grid[i].size()-1;j>=0;j--){
                    c++;
                    if(c%2!=0){
                        ans.push_back(grid[i][j]);
                    }
                }
            }
            left=!left;
        }
        return ans;
    }
};