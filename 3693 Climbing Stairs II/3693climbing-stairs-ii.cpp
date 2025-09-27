class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> stored=costs;
        vector<int> temp(n+1,INT_MAX);
        temp[0]=0; 
        for(int i=0;i<=n;i++){
            if(temp[i]==INT_MAX){
                continue;
            }
            for(int j=i+1;j<=min(i+3,n);j++){
                int cost=temp[i]+stored[j-1]+(j-i)*(j-i);
                if(cost<temp[j]){
                    temp[j]=cost;
                }
            }
        }
        return temp[n];
    }
};