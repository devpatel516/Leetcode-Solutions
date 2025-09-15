class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        set<char> bl;
        for(auto c:brokenLetters){
            bl.insert(c);
        }
        int ans=0;
        int i;
        for(i=0;i<text.size();i++){
            if(bl.contains(text[i])){
                while(i<text.size() && text[i]!=' '){
                    i++;
                }
                // i++;
                // cout<<i<<endl;
                // continue;
            }
            else if(text[i]==' ' || i==text.size()-1){
                ans++;
            }
        }
        return ans;
    }
};