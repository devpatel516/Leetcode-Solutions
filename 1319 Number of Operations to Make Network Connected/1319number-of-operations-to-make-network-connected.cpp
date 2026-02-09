class DisjointSet{
    public:
        vector<int> parent,rank;
        DisjointSet(int n){
            parent.resize(n+1,0);
            rank.resize(n+1);
            for(int i=0;i<=n;i++){
                parent[i]=i;
            }
        }

        int findUPar(int node){
            if(node==parent[node]){
                return node;
            }
            return parent[node]=findUPar(parent[node]);
        }

        void unionByRank(int u,int v){
            int ulp_u=findUPar(u);
            int ulp_v=findUPar(v);
            if(ulp_u==ulp_v){
                return;
            }
            if(rank[ulp_u]<rank[ulp_v]){
                parent[ulp_u]=ulp_v;
            }
            else if(rank[ulp_v]<rank[ulp_u]){
                parent[ulp_v]=ulp_u;
            }
            else{
                parent[ulp_v]=ulp_u;
                rank[ulp_u]++;
            }
        }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int ce=0;
        for(auto e:connections){
            int u=e[0];
            int v=e[1];
            if(ds.findUPar(u)==ds.findUPar(v)){
                ce++;
            }
            else{
                ds.unionByRank(u,v);
            }
        }
        int cc=0;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i){
                cc++;
            }
        }
        cout<<ce<<" "<<cc<<endl;
        if(ce>=cc-1){
            return cc-1;
        }
        else{
            return -1;
        }
    }
};