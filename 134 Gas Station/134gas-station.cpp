class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> gain;
        for(int i=0;i<gas.size();i++){
            gain.push_back(gas[i]-cost[i]);
        }
        int total=0;
        for(auto x:gain){
            total+=x;
        }
        if(total<0){
            return -1;
        }

        int tank=0;
        int ans=0;
        for(int i=0;i<gas.size();i++){
            tank+=gain[i];
            if(tank<0){
                ans=i+1;
                tank=0;
            }
        }
        return ans;
    }
};