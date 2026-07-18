class Solution {
public:
    int MOD=1000000007;
    int solve(int column,int n,string state,vector<unordered_map<string,int>> &dp){
        if(column==n){
            if(state=="complete"){
                return 1;
            }
            return 0;
        }
        if(column>n){
            return 0;
        }
        if(dp[column].find(state)!=dp[column].end()){
            return dp[column][state];
        }
        int c=0;
        if(state=="complete"){
            //place one vertical
            c=(c+solve(column+1,n,"complete",dp))%MOD;

            //place two horizontal
            c=(c+solve(column+2,n,"complete",dp))%MOD;

            //place tromino in L manner
            c=(c+solve(column+1,n,"missing top",dp))%MOD;

            //place tromini in upside down L manner
            c=(c+solve(column+1,n,"missing bottom",dp))%MOD;
        }else if(state=="missing top"){
            //fill top with horizontal bar
            c=(c+solve(column+1,n,"missing bottom",dp))%MOD;
            
            //fill that with tromino 
            c=(c+solve(column+2,n,"complete",dp))%MOD;
        }else if(state=="missing bottom"){
            //fill that with tromino
            c=(c+solve(column+2,n,"complete",dp))%MOD;
            //fill bottom with horizontal bar
            c=(c+solve(column+1,n,"missing top",dp))%MOD;
        }
        return dp[column][state]=c%MOD;
    }
    int numTilings(int n) {
        vector<unordered_map<string,int>> dp(n+1);
        return solve(0,n,"complete",dp);
    }
};