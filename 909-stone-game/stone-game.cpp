class Solution {
public:
    vector<vector<vector<int>>> dp;
    int solve(vector<int> &piles,int l,int h,bool play){
        if(l>h){
            return 0;
        }
        if(dp[l][h][play]!=-1){
            return dp[l][h][play];
        }
        int alice=0,bob=0;
        if(play){
            alice=max(piles[l]+solve(piles,l+1,h,false),piles[h]+solve(piles,l,h-1,false));
            return dp[l][h][play]=alice;
        }else{
            bob=min(-piles[l]+solve(piles,l+1,h,true),-piles[h]+solve(piles,l,h-1,true));
            return dp[l][h][play]=bob;
        }
    }
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        dp.assign(n,vector<vector<int>>(n,vector<int>(2,-1)));
        int temp=solve(piles,0,n-1,true);
        return temp>0?true:false;
    }
};