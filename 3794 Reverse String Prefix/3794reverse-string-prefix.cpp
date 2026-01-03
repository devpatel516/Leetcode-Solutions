class Solution {
public:
    string reversePrefix(string s, int k) {
        string t=s.substr(0,k);
        reverse(t.begin(),t.end());
        for(int i=k;i<s.size();i++){
            t+=s[i];
        }
        cout<<t<<endl;
        return t;
    }
};