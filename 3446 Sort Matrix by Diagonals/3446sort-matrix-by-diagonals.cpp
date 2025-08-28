class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        unordered_map<int,vector<int>> m;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                m[i-j].push_back(grid[i][j]);
            }
        }
        for(auto &k:m){
            if(k.first>=0){
                sort(k.second.begin(),k.second.end());
            }
            else{
                sort(k.second.rbegin(),k.second.rend());
            }
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                grid[i][j]=m[i-j].back();
                m[i-j].pop_back();
            }
        }
        return grid;
    }
};
// -5 -5 -3
// -2 -1 -2
//  0 -3 -1

// -1 -5 -3
// -2 -1 -2
//  0 -3 -5