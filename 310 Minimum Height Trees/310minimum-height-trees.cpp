class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1){
            return {0};
        }
        vector<vector<int>> adj(n);
        vector<int> degree(n,0);

        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            degree[e[0]]++;
            degree[e[1]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(degree[i]==1){
                q.push(i);
            }
        }

        int remains=n;
        while(remains>2){
            int size=q.size();
            remains-=size;

            while(size--){
                int node=q.front();
                q.pop();
                for(auto it:adj[node]){
                    degree[it]--;
                    if(degree[it]==1){
                        q.push(it);
                    }
                }
            }
        }
        vector<int> result;
        while(!q.empty()){
            result.push_back(q.front());
            q.pop();
        }
        return result;
    }
};