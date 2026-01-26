class Solution {
public:
    vector<int> toposort(int k,vector<vector<int>> &edges){
        vector<vector<int>> adj(k+1);
        vector<int> inDegree(k+1,0);
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
        }

        for(int i=1;i<=k;i++){
            for(auto it:adj[i]){
                inDegree[it]++;
            }
        }

        queue<int> q;
        for(int i=1;i<=k;i++){
            if(inDegree[i]==0){
                q.push(i);
            }
        }
        vector<int> res;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            res.push_back(node);
            for(auto it:adj[node]){
                inDegree[it]--;
                if(inDegree[it]==0){
                    q.push(it);
                }
            }
        }
        return res;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> vertical=toposort(k,rowConditions);
        vector<int> horizontal=toposort(k,colConditions);
        unordered_map<int,int> mp;
        for(int i=0;i<horizontal.size();i++){
            mp[horizontal[i]]=i;
        }
        if(vertical.size()!=k || horizontal.size()!=k){
            return {};
        }
        // for(auto x:vertical){
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        // for(auto x:horizontal){
        //     cout<<x<<" ";
        // }
        vector<vector<int>> ans(k,vector<int>(k,0));
        for(int i=0;i<vertical.size();i++){
            ans[i][mp[vertical[i]]]=vertical[i];
        }
        return ans;
    }
};