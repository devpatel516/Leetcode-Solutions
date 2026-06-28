class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        vector<vector<int>> temp;
        sort(occupiedIntervals.begin(),occupiedIntervals.end());
        for(auto c:occupiedIntervals){
            if(temp.empty() || c[0]>temp.back()[1]+1){
                temp.push_back(c);
            }else{
               temp.back()[1]=max(temp.back()[1],c[1]); 
            }
        }

        vector<vector<int>> ans;
        for(auto v:temp){
            if(v[1]<freeStart || v[0]>freeEnd){
                ans.push_back({v[0],v[1]});
            }else{
                if(v[0]<freeStart){
                    ans.push_back({v[0],freeStart-1});
                }
                if(v[1]>freeEnd){
                    ans.push_back({freeEnd+1,v[1]});
                }
            }
        }
        return ans;
    }
};