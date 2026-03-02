class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        //slope=y2-y1*(x3-x1)=(y3-y1)*x2-x1
        int x1=coordinates[0][0];
        int x2=coordinates[1][0];
        int y1=coordinates[0][1];
        int y2=coordinates[1][1];
        for(int i=2;i<coordinates.size();i++){
            if((y2-y1)*(coordinates[i][0]-x1)!=(coordinates[i][1]-y1)*(x2-x1)){
                return false;
            }
        }
        return true;
    }
};