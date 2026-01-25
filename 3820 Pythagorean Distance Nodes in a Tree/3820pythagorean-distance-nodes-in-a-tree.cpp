class Solution {
public:
    vector<long long> shortestPath(long long src,vector<vector<long long>> &adj){
        long long n=adj.size();
        vector<long long> dist(n,-1);
        queue<pair<long long,long long>> q;
        q.push({src,0});
        dist[src]=0;
        while(!q.empty()){
            long long node=q.front().first;
            long long d=q.front().second;
            q.pop();
            if(dist[node]==-1){
                dist[node]=d;
            }
            for(auto it:adj[node]){
                if(dist[it]==-1){
                    q.push({it,d+1});
                }
            }
        }
        return dist;
    }
    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        vector<vector<long long>> adj(n);

        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<long long> dx=shortestPath(x,adj);
        vector<long long> dy=shortestPath(y,adj);
        vector<long long> dz=shortestPath(z,adj);
        long long ans=0;
        for(long long i=0;i<n;i++){
            long long a=dx[i],b=dy[i],c=dz[i];
            vector<long long> temp;
            temp.push_back(a);
            temp.push_back(b);
            temp.push_back(c);
            sort(temp.begin(),temp.end());

            if((temp[0]*temp[0]+temp[1]*temp[1])==(temp[2]*temp[2])){
                ans++;
            }
        }
        return ans;
    }
};