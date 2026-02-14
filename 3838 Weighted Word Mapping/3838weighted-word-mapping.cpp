class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans;
        for(int i=0;i<words.size();i++){
            int t=0;
            for(int j=0;j<words[i].size();j++){
                int c=words[i][j]-'a';
                t+=weights[c];
            }
            ans+='a'+25-(t%26);
        }
        return ans;
    }
};