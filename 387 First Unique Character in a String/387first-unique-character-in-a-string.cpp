class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> f(26);
        for(int i=0;i<s.size();i++){
            f[s[i]-'a']+=1;
        }
        int c=-1;
        for(int i=0;i<s.size();i++){
            if(f[s[i]-'a']==1){
                c=i;
                break;
            }
        }
        return c;
    }
};