class Solution {
public:
    int dx[4]={-1,0,1,0};
    int dy[4]={0,-1,0,1};
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<
        pair<int, pair<int,int>>,
        vector<pair<int, pair<int,int>>>,
        greater<pair<int, pair<int,int>>>
        > pq;

        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        dist[0][0]=0;
        pq.push({0,{0,0}});

        while(!pq.empty()){
            int diff=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();
            if(row==n-1 && col==m-1){
                return diff;
            }

            for(int i=0;i<4;i++){
                int nr=row+dx[i];
                int nc=col+dy[i];

                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    int newEffort=max(abs(heights[row][col]-heights[nr][nc]),diff);
                    if(newEffort<dist[nr][nc]){
                        dist[nr][nc]=newEffort;
                        pq.push({newEffort,{nr,nc}});
                    }
                }
            }
        }
        return 0;
    }
};