class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        float maxi=0;
        int aream=0;
        for(int i=0;i<dimensions.size();i++){
            int x=dimensions[i][0];
            int y=dimensions[i][1];
            float length=x*x+y*y;
            if(length>maxi){
                maxi=length;
                aream=x*y;
            }
            else if(length==maxi){
                aream=max(aream,x*y);
            }
        }
        return aream;
    }
};