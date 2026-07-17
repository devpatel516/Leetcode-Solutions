class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<string,int> r;
        unordered_map<string,int> c;
        int n=grid.size();
        for(int i=0;i<n;i++){
            string temp="";
            for(int j=0;j<n;j++){
                temp+=to_string(grid[i][j])+",";
            }
            r[temp]++;
        }
        for(int i=0;i<n;i++){
            string temp="";
            for(int j=0;j<n;j++){
                temp+=to_string(grid[j][i])+",";
            }
            c[temp]++;
        }
        int a=0;
        for(auto k:r){
            if(c.contains(k.first)){
                a+=(r[k.first]*c[k.first]);
            }
        }
        return a;
    }
};