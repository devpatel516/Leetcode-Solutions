class Solution {
public:
    vector<int> ans;
    vector<int> vis;
    bool dfs(int x,int n){
        vis[x]=1;
        ans.push_back(x);
        if(ans.size()==(1<<n)){
            return true;
        }

        for(int i=0;i<n;i++){
            int next=x^(1<<i);
            if(!vis[next]){
                if(dfs(next,n)){
                    return true;
                }
            }
        }
        vis[x]=0;
        ans.pop_back();
        return false;
    }
    vector<int> grayCode(int n) {
        vis.assign(1<<n,0);
        bool v=dfs(0,n);
        return ans;
    }
};