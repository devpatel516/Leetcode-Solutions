class Solution {
public:
    void solve(vector<int> &freq,int &ans){
        for(int i=0;i<26;i++){
            if(freq[i]==0){
                continue;
            }
            ans++;
            freq[i]--;
            solve(freq,ans);
            freq[i]++;
        }
    }
    int numTilePossibilities(string tiles) {
        vector<int> freq(26,0);

        for(int i=0;i<tiles.size();i++){
            freq[tiles[i]-'A']++;
        }

        int ans=0;
        solve(freq,ans);
        return ans;
    }
};