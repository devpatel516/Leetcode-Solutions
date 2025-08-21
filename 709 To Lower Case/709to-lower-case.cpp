class Solution {
public:
    string toLowerCase(string s) {
        string x="";
        for(auto c:s){
            x+=tolower(c);
        }
        return x;
    }
};