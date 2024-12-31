class Solution {
public:
    bool areOccurrencesEqual(string s) {
        map<char,int> m;
        for(auto c:s){
            m[c]++;
        }
        int freq=m.begin()->second;
        for(auto i:m){
            if(i.second!=freq){
                return false;
            }
        }
        return true;
    }
};