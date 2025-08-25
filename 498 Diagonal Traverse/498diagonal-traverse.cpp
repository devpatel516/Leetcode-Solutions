class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        int m=mat.size();
        int n=mat[0].size();
        for(int d=0;d<m+n-1;d++){
            vector<int> temp;
            for(int i=0;i<m;i++){
                int j=d-i;
                if(j>=0 && j<n){
                    temp.push_back(mat[i][j]);
                }
            }
            if(d%2==0){
                reverse(temp.begin(),temp.end());
            }
            ans.insert(ans.end(),temp.begin(),temp.end());
        }
        return ans;
    }
};