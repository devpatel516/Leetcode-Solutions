class Solution {
public:
    bool isPossibleToRearrange(string s, string t, int k) {
        vector<string> a,b;
        int x=s.size()/k;
        for(int i=0;i<s.size();i+=x){
            a.push_back(s.substr(i,x));
        }
        sort(a.begin(),a.end());
        for(int i=0;i<t.size();i+=x){
            b.push_back(t.substr(i,x));
        }
        sort(b.begin(),b.end());

        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i]){
                return false;
            }
        }
        return true;
    }
};