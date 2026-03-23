class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int c=y;
        int t=k;
        while(t--){
            int l=x;
            int r=x+k-1;
            //cout<<l<<" "<<r<<endl;
            while(l<r){
                swap(grid[l][c],grid[r][c]);
                l++;
                r--;
            }
            //cout<<c<<endl;
            c++;
        }
        return grid;
    }
};
// 1 2 3 4
// 9 6 7 8
// 5 10 11 12
// 13 14 15 16