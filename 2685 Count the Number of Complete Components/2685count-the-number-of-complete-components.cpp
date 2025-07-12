class Solution {
public:
    void bfs(int node,vector<vector<int>> adj,vector<int> &list,vector<int> &vis){
        queue<int> q;
        q.push(node);
        vis[node]=1;
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            list.push_back(node);
            for(auto it:adj[node]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n,0);
        int ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                vector<int> list;
                bfs(i,adj,list,vis);
                bool complete=true;
                for(auto i:list){
                    if(adj[i].size()!=list.size()-1){
                        complete=false;
                    }
                }
                if(complete) ans++;
            }
        }
        return ans;
    }
};