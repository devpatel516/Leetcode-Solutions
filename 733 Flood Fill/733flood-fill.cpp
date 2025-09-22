class Solution {
private:
    int dr[4]={-1,1,0,0};
    int dc[4]={0,0,-1,1};
    void dfs(int row,int col,int color,int init,vector<vector<int>> &ans,vector<vector<int>> &image){
        ans[row][col]=color;
        int m=image.size();
        int n=image[0].size();

        for(int i=0;i<4;i++){
            int nr=row+dr[i];
            int nc=col+dc[i];
            if(nr>=0 && nr<m && nc>=0 && nc<n && image[nr][nc]==init && ans[nr][nc]!=color){
                dfs(nr,nc,color,init,ans,image);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int init=image[sr][sc];
        vector<vector<int>> ans=image;
        dfs(sr,sc,color,init,ans,image);
        return ans;
    }
};