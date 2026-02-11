class Solution {
public:
    const long long MOD=1e9+7;
    vector<long long> bfs(vector<vector<pair<int,int>>> &adj){
        int n=adj.size();
        vector<long long> res(n,0);
        vector<int> vis(n,0);
        res[0]=1;
        queue<int> q;
        q.push(0);
        vis[0]=1;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it:adj[node]){
                int v=it.first;
                int wt=it.second;
                if(!vis[v]){
                    res[v]=(res[node]*wt)%MOD;
                    q.push(v);
                    vis[v]=1;
                }
            }
        }
        return res;
    }
    vector<int> baseUnitConversions(vector<vector<int>>& conversions) {
        int n=conversions.size()+1;
        vector<int> ans(n);
        vector<vector<pair<int,int>>> adj(n);
        for(auto e:conversions){
            adj[e[0]].push_back({e[1],e[2]});
        }
        vector<long long> a=bfs(adj);
        for(int i=0;i<n;i++){
            ans[i]=(int)a[i];
        }
        return ans;
    }
};