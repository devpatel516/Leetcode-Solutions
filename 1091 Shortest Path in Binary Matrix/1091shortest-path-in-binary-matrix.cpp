class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        queue<pair<int,pair<int,int>>> q; //{dis,{x,y}}
        vector<vector<int>> dist(n,vector<int> (n,INT_MAX));
        int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        if(n==1 && grid[0][0]==0){
            return 1;
        }
        if(grid[0][0]==1 || grid[n-1][n-1]==1){
            return -1;
        }
        q.push({1,{0,0}});
        dist[0][0]=0;

        while(!q.empty()){
            int dis=q.front().first;
            int x=q.front().second.first;
            int y=q.front().second.second;
            q.pop();
            for(int i=0;i<8;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];

                if(nx>=0 && nx<n && ny>=0 && ny<n && grid[nx][ny]==0 && dis+1<dist[nx][ny]){
                    dist[nx][ny]=dis+1;
                    if(nx==n-1 && ny==n-1){
                        return dis+1;
                    }
                    q.push({dis+1,{nx,ny}});
                }
            }
        }
        return -1;
    }
};