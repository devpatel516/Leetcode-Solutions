class Solution {
public:
    bool solve(int i,vector<int>& arr,vector<bool>& vis){
        if(i<0 || i>=arr.size()){
            return false;
        }
        if(arr[i]==0){
            return true;
        }
        if(vis[i]){
            return false;
        }
        vis[i]=true;
        return solve(i+arr[i],arr,vis) || solve(i-arr[i],arr,vis);
    }
    bool canReach(vector<int>& arr, int start) {
        vector<bool> vis(arr.size(),false);
        return solve(start,arr,vis);
    }
};