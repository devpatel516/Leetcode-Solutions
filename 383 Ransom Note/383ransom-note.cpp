class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char,int> c;
        for(auto x:magazine){
            c[x]++;
        }
        for(auto x:ransomNote){
            if(c[x]==0){
                return false;
            }
            c[x]--;
        }
        return true;
    }
};