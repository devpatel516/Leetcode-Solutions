class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        deque<int> q;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                q.push_back(grid[i][j]);
            }
        }
        int t=k%q.size();
        while(t--){
            int temp=q.back();
            q.pop_back();
            q.push_front(temp);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                grid[i][j]=q.front();
                q.pop_front();
            }
        }
        return grid;
    }
};