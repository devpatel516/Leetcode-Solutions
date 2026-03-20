class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> ans(n-k+1,vector<int>(m-k+1));
        for(int i=0;i<=n-k;i++){
            for(int j=0;j<=m-k;j++){
                set<int> s;
                for(int x=i;x<i+k;x++){
                    for(int y=j;y<j+k;y++){
                        s.insert(grid[x][y]);
                    }
                }
                vector<int> temp(s.begin(),s.end());
                sort(temp.begin(),temp.end());
                //cout<<s.size()<<endl;
                if(temp.size()<=1){
                    ans[i][j]=0;
                }
                else{
                    int mini=INT_MAX;
                    for(int v=0;v<temp.size()-1;v++){
                        mini=min(temp[v+1]-temp[v],mini);
                    }
                    ans[i][j]=mini;
                }
            }
        }  
        return ans;
    }
};