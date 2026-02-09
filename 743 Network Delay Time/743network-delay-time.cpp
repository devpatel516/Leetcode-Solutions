class Solution {
public:
    vector<int> dijkstra(int n,int src,vector<vector<pair<int,int>>> &adj){
        vector<int> dist(n+1,INT_MAX);
        dist[src]=0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        q.push({src,0});
        while(!q.empty()){
            int node=q.top().first;
            int d=q.top().second;
            q.pop();
            for(auto it:adj[node]){
                int adjNode=it.first;
                int wt=it.second;

                if(d+wt<dist[adjNode]){
                    dist[adjNode]=d+wt;
                    q.push({adjNode,d+wt});
                }
            }
        }    
        return dist;  
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto t:times){
            adj[t[0]].push_back({t[1],t[2]});
        }
        vector<int> dist=dijkstra(n,k,adj);
        int ans=INT_MIN;
        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX){
                return -1;
            }
            ans=max(ans,dist[i]);
        }
        return ans;
    }
};