class Solution {
public:
    int minimumPartition(string s, int k) {
        string temp="";
        int ans=0,i=0;
        while(i<s.size()){
            temp="";
            while(i<s.size() && stoll(temp+s[i])<=k){
                temp+=s[i];
                i++;
            }
            if(temp.empty()){
                return -1;
            }
            ans++;
        }
        return ans;
    }
};