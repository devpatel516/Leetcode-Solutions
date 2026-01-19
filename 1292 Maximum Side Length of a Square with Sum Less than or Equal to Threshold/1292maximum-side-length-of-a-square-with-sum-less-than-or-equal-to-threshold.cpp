class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n=mat.size();
        int m=mat[0].size();

        vector<vector<int>> ps(n+1,vector<int> (m+1,0));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                ps[i][j]=mat[i-1][j-1]+ps[i-1][j]+ps[i][j-1]-ps[i-1][j-1];
            }
        }
        int s=min(n,m);
        int res=0;
        while(s){
            for(int i=s;i<=n;i++){
                for(int j=s;j<=m;j++){
                    int sum=ps[i][j]-ps[i-s][j]-ps[i][j-s]+ps[i-s][j-s];
                    if(sum<=threshold){ 
                        res=max(res,s); 
                    }
                }
            }
            s--;
        }
        return res;
    }
};