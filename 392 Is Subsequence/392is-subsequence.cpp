class Solution {
public:
    bool isSubsequence(string s, string t) {
        int left=0,right=0,c=0;
        if(s.empty()) return true;
        if(t.empty()) return false;
        while(left<=s.size()-1 && right<=t.size()-1){
            if(s[left]==t[right]){
                c++;
                left++;
                right++;
            }
            else{
                right++;
            }
        }
        if(c==s.size()){
            return true;
        }
        return false;
    }
};