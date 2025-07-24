class Solution {
public:
    string customSortString(string order, string s) {
       unordered_map<char,int> m;
       for(int i=0;i<s.size();i++){
        m[s[i]]++;
       }
       string res="";
       for(auto k:order){
        if(m.find(k)!=m.end()){
            while(m[k]--){
                res+=k;
            }
        }
       }
       for(auto k:m){
            while(k.second-->=1){
                res+=k.first;
            }
       }
       return res;
    }
};