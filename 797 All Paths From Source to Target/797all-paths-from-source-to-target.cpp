class Solution {
public:
    void dfs(int i,vector<int> temp,vector<vector<int>> &ans,vector<vector<int>> &adj,vector<int> &vis){
        vis[i]=1;
        temp.push_back(i);
        if(i==adj.size()-1){
            ans.push_back(temp);
            vis[i]=0;
            return ;
        }
        for(auto it:adj[i]){
            if(!vis[it]){
                dfs(it,temp,ans,adj,vis);
                vis[it]=0;
            }
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> vis(n,0),temp;
        vector<vector<int>> ans;
        dfs(0,temp,ans,graph,vis);
        return ans;
    }
};