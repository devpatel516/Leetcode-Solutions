class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,vector<int>> mp;
        for(auto e:edges){
            int u=e[0];
            int v=e[1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        vector<int> visited(n,-1);
        queue<int> q;
        q.push(source);
        visited[source]=1;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            if(node == destination){
                return true;
            }
            for(auto v:mp[node]){
                if(visited[v]==-1){
                    q.push(v);
                    visited[v]=1;
                }
            }
        }
        return false;
    }
};