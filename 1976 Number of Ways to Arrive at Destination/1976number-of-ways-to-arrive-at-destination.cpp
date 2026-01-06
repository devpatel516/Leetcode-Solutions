class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        vector<vector<pair<long long,long long>>> adj(n);

        for(auto &it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }

        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> pq;
        vector<long long> dist(n,LLONG_MAX),ways(n,0);

        dist[0]=0;
        ways[0]=1;
        pq.push({0,0});

        while(!pq.empty()){
            auto [dis,node]=pq.top();
            pq.pop();

            //if(dis>dist[node]) continue;

            for(auto &it:adj[node]){
                long long adjNode=it.first;
                long long wt=it.second;

                if(dis+wt<dist[adjNode]){
                    dist[adjNode]=dis+wt;
                    ways[adjNode]=ways[node];
                    pq.push({dist[adjNode],adjNode});
                }
                else if(dis+wt==dist[adjNode]){
                    ways[adjNode]=(ways[adjNode]+ways[node])%MOD;
                }
            }
        }
        return ways[n-1];
    }
};
