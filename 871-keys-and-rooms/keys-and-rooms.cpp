class Solution {
public:
    void solve(int i,vector<int> &vis,vector<vector<int>>& rooms){
        vis[i]=1;
        for(auto node:rooms[i]){
            if(!vis[node]){
                solve(node,vis,rooms);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int> vis(n,0);
        solve(0,vis,rooms);
        for(int i=0;i<n;i++){
            if(vis[i]!=1){
                return false;
            }
        }
        return true;
    }
};