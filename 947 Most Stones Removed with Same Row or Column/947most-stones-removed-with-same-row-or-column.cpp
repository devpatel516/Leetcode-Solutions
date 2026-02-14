class DisjointSet{
    public:
        vector<int> parent,rank,size;
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
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        int maxRow=0;
        int maxCol=0;
        for(auto it:stones){
            maxRow=max(it[0],maxRow);
            maxCol=max(it[1],maxCol);
        }
        DisjointSet ds(maxRow+maxCol+1);
        unordered_map<int,int> stoneNodes;
        for(auto it:stones){
            int row=it[0];
            int col=it[1]+maxRow+1;
            ds.unionByRank(row,col);
            stoneNodes[row]=1;
            stoneNodes[col]=1;
        }
        int c=0;
        for(auto it:stoneNodes){
            if(ds.findUPar(it.first)==it.first){
                c++;
            }
        }
        return n-c;
    }
};