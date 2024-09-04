class Solution {
public:
    string finalString(string s) {
        string d;
        char x;
        for(auto x:s){
            if(x=='i'){
                reverse(d.begin(),d.end());
            }
            else{
                d+=x;
            }
        }
        return d;
    }
};