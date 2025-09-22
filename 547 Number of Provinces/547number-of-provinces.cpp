class Solution {
public:
    void dfs(int start,vector<int> &vis,vector<vector<int>> &adj){
        vis[start]=1;
        for(auto it:adj[start]){
            if(vis[it]==0){
                dfs(it,vis,adj);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> vis(isConnected.size(),0);
        vector<vector<int>> adjacency(isConnected.size());
        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected.size();j++){
                if(isConnected[i][j]==1 && i!=j){
                    adjacency[i].push_back(j);
                    adjacency[j].push_back(i);
                }
            }
        }
        int c=0;
        for(int i=0;i<vis.size();i++){
            if(vis[i]==0){
                dfs(i,vis,adjacency);
                c++;
            }
        }
        return c;
    }
};