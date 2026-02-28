class Solution {
public:
    string mergeCharacters(string s, int k) {
        string t="";
        unordered_map<char,int> mp;
        for(int i=0;i<s.size();i++){
            if(mp.find(s[i])!=mp.end()){
                if(t.size()-mp[s[i]]>k){
                    mp[s[i]]=t.size();
                    t+=s[i];
                }
            }
            else{    
                mp[s[i]]=t.size();
                t+=s[i];
            }
        }
        return t;
    }
};