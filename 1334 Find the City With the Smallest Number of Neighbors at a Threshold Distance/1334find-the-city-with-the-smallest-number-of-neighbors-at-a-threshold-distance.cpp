class Solution {
public:
    void floydWarshall(vector<vector<int>> &adj){
        int n=adj.size();
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(adj[i][k]==-1 || adj[k][j]==-1){
                        continue;
                    }

                    if(adj[i][j]==-1){
                        adj[i][j]=adj[i][k]+adj[k][j];
                    }
                    else{
                        adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);
                    }
                }
            }
        }
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> adj(n,vector<int>(n,-1));
        for(auto e:edges){
            int u=e[0];
            int v=e[1];
            int d=e[2];
            adj[u][v]=d;
            adj[v][u]=d;
        }
        floydWarshall(adj);
        for(int i=0;i<n;i++){
            adj[i][i]=0;
        }
        vector<int> temp(n);
        for(int i=0;i<n;i++){
            int c=0;
            for(int j=0;j<n;j++){
                if(adj[i][j]!=-1 && adj[i][j]<=distanceThreshold){
                    c++;
                }
            }
            temp[i]=c;
            cout<<temp[i]<<" ";
        }
        int ans=INT_MAX;
        int ind=-1;
        for(int i=0;i<n;i++){
            cout<<temp[i]<<" "<<ans<<endl;
            if(temp[i]<=ans){
                ans=temp[i];
                ind=i;
            }
        }
        return ind;
    }
};