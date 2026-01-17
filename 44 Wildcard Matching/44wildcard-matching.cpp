class Solution {
public:
    vector<vector<int>> dp;

    bool func(int i, int j, string &s, string &p){
        if(i < 0 && j < 0) return true;
        if(j < 0 && i >= 0) return false;

        if(i < 0 && j >= 0){
            for(int k = 0; k <= j; k++){
                if(p[k] != '*') return false;
            }
            return true;
        }

        if(dp[i][j] != -1) 
            return dp[i][j];

        bool ans = false;

        if(s[i] == p[j] || p[j] == '?'){
            ans = func(i-1, j-1, s, p);
        }
        else if(p[j] == '*'){
            ans = func(i, j-1, s, p) || func(i-1, j, s, p);
        }

        return dp[i][j] = ans;
    }

    bool isMatch(string s, string p) {
        dp.assign(s.size(), vector<int>(p.size(), -1));
        return func(s.size()-1, p.size()-1, s, p);
    }
};
