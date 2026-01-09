class Solution {
public:
    bool func(int node,int col,vector<int> &color,vector<vector<int>>& adj){
        color[node]=col;
        for(auto it:adj[node]){
            if(color[it]==-1){
                if(func(it,!col,color,adj)==false){
                    return false;
                }
            }
            else if(color[it]==col){
                return false;
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n+1);
        for(auto k:dislikes){
            adj[k[0]].push_back(k[1]);
            adj[k[1]].push_back(k[0]);
        }
        vector<int> color(n+1,-1);
        for(int i=1;i<=n;i++){
            if(color[i]==-1){
                if(!func(i,0,color,adj)){
                    return false;
                }
            }
        }
        return true;
    }
};