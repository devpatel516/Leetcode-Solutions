class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> inDegree(n,0);

        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
        }

        for(int i=0;i<n;i++){
            for(auto it:adj[i]){
                inDegree[it]++;
            }
        }

        vector<set<int>> ancestors(n);
        queue<int> q;
        for(int i=0;i<n;i++){
            if(inDegree[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node=q.front();
            q.pop();

            for(auto it:adj[node]){
                ancestors[it].insert(node);
                ancestors[it].insert(ancestors[node].begin(),ancestors[node].end());
                inDegree[it]--;
                if(inDegree[it]==0){
                    q.push(it);
                }
            }
        }

        vector<vector<int>> ans(n);
        for(int i=0;i<n;i++){
            ans[i]=vector<int>(ancestors[i].begin(),ancestors[i].end());
        }
        return ans;
    }
};