class Solution {
public:
    vector<double> dijkstra(int n,vector<vector<pair<int,double>>> &adj,int src){
        vector<double> dist(n,0.0);
        priority_queue<pair<double,int>> pq;
        dist[src]=1;
        pq.push({1.0,src});

        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();
            double p=top.first;
            int node=top.second;
            
            for(auto it:adj[node]){
                double pp=it.second;
                int adjNode=it.first;

                if(p*pp>dist[adjNode]){
                    dist[adjNode]=p*pp;
                    pq.push({p*pp,adjNode});
                }
            }
        }
        return dist;
    }
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>> adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        vector<double> dist=dijkstra(n,adj,start_node);
        for(auto k:dist){
            cout<<k<<" ";
        }
        return dist[end_node];
    }
};