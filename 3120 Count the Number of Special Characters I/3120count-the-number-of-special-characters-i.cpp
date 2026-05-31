class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char,int> mp;
        for(auto ch:word){
            mp[ch]++;
        }
        int ans=0;
        for(int i=0;i<word.size();i++){
            if(islower(word[i]) && mp.find(toupper(word[i]))!=mp.end()){
                ans++;
                mp.erase(tolower(word[i]));
                mp.erase(toupper(word[i]));
            }
        }
        return ans;
    }
};