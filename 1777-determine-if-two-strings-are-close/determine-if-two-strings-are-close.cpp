class Solution {
public:
    bool closeStrings(string word1, string word2) {
        unordered_map<char,int> mp1,mp2;
        int m1=0;
        int m2=0;
        for(auto c:word1){
            mp1[c]++;
            m1=max(m1,mp1[c]);
        }
        for(auto c:word2){
            mp2[c]++;
            m2=max(m2,mp2[c]);
        }
        for(int i=0;i<word1.size();i++){
            if(!mp2.contains(word1[i])){
                return false;
            }
        }
        vector<int> t1(m1+1,0),t2(m2+1,0);
        for(auto k:mp1){
            t1[k.second]++;
        }
        for(auto k:mp2){
            t2[k.second]++;
        }
        if(t1.size()!=t2.size()){
            return false;
        }
        for(int i=0;i<t1.size();i++){
            if(t1[i]!=t2[i]){
                return false;
            }
        }
        return true;
    }
};