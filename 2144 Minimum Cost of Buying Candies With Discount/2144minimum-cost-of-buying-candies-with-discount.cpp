class Solution {
public:
    struct compare{
        bool operator()(auto a,auto b){
            return a>b;
        }
    };
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end(),compare());
        int ans=0;
        for(int i=0;i<cost.size();i++){
            if((i+1)%3==0){
                continue;
            }
            ans+=cost[i];
        }
        return ans;
    }
};