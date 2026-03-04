class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int ans=0;
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    continue;
                }
                int r=i;
                int c=j;
                bool valid=true;
                for(int k=0;k<m;k++){
                    if(mat[r][k]==1 && k!=j){
                        valid=false;
                        break;
                    }
                }
                if(!valid){
                    continue;
                }
                for(int k=0;k<n;k++){
                    if(mat[k][c]==1 && k!=i){
                        valid=false;
                        break;
                    }
                }
                if(!valid){
                    continue;
                }
                ans++;
            }
        }
        return ans;
    }
};