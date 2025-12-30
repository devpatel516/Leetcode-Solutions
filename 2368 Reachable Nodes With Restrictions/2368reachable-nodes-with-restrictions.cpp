class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<vector<int>> adj(n+1);
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> vis(n+1,0);
        unordered_set<int> s(restricted.begin(),restricted.end());
        queue<int> q;
        q.push(0);
        vis[0]=1;
        int ans=1;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int p=q.front();
                q.pop();

                for(auto node:adj[p]){
                    if(s.count(node)){
                        continue;
                    }
                    else if(!vis[node]){
                        q.push(node);
                        vis[node]=1;
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};