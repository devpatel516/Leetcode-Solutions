class Solution {
public:
    vector<int> dx={-1,1,0,0};
    vector<int> dy={0,0,-1,1};
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        vector<vector<int>> grid(n,vector<int>(m,0)),time(n,vector<int>(m,INT_MAX));
        queue<tuple<int,int,int,int>> q;
        for(auto e:sources){
            grid[e[0]][e[1]]=e[2];
            time[e[0]][e[1]]=0;
            q.push({e[0],e[1],e[2],0});
        }
        while(!q.empty()){
            auto [r,c,p,t]=q.front();
            q.pop();

            for(int i=0;i<4;i++){
                int nr=r+dx[i];
                int nc=c+dy[i];

                if(nr>=0 && nr<n && nc>=0 && nc<m && time[nr][nc]>t+1){
                    grid[nr][nc]=p;
                    time[nr][nc]=t+1;
                    q.push({nr,nc,p,t+1});
                }
                else if(nr>=0 && nr<n && nc>=0 && nc<m && time[nr][nc]==t+1){
                    if(grid[nr][nc]<p){
                        grid[nr][nc]=p;
                        q.push({nr,nc,p,t+1});
                    }
                }
            }
        }
        return grid;
    }
};