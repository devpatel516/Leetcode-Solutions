class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> res,lp,gp,ep;
        for(auto c:nums){
            if(c<pivot){
                lp.push_back(c);
            }
            else if(c>pivot){
                gp.push_back(c);
            }
            else{
                ep.push_back(c);
            }
        }
        for(auto c:lp){
            res.push_back(c);
        }
        for(auto c:ep){
            res.push_back(c);
        }
        for(auto c:gp){
            res.push_back(c);
        }
        return res;
    }
};