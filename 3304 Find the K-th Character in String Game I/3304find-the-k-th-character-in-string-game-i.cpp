class Solution {
public:
    char kthCharacter(int k) {
        string s="a";
        while(s.size()<k){
            int size=s.size();
            for(int i=0;i<size;i++){
                char next='a'+(s[i]-'a'+1)%26;
                s+=next;
            }
        }
        return s[k-1];
    }
};