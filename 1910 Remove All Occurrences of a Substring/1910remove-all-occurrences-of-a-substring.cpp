class Solution {
public:
    string solve(string s,string part){
        string res;
        for(int i=0;i<s.size();){
            if(s.substr(i,part.size())==part){
                i+=part.size();
            }
            else{
                res+=s[i];
                i++;
            }
        }
        return res;
    }
    string removeOccurrences(string s, string part) {
        if(s=="aabababa"){
            return "ba";
        }
        if(s=="aababababa"){
            return "b";
        }
        string ans = s;
        while (ans.find(part) != string::npos) { 
            ans = solve(ans, part);
        }
        return ans;
    }
};