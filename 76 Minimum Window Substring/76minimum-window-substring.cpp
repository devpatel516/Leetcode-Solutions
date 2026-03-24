class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mp;
        for(auto c:t){
            mp[c]++;
        }
        int req=t.size();
        int len=INT_MAX;
        int st=0,l=0;
        for(int r=0;r<s.size();r++){
            if(mp[s[r]]>0){
                req--;
            }
            mp[s[r]]--;
            while(req==0){
                if((r-l+1)<len){
                    len=r-l+1;
                    st=l;
                }
                mp[s[l]]++;
                if(mp[s[l]]>0){
                    req++;
                }
                l++;
            }
        }
        if(len==INT_MAX){
            return "";
        }
        else{
            return s.substr(st,len);
        }
    }
};