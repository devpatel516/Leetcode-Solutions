class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char,int> mp;
        for(auto c:word){
            mp[c]++;
        }
        int ans=0;
        //c-2
        //C-2
        //e-1
        //D-1
        for(int i=0;i<word.size();i++){
            if(islower(word[i])){
                mp[word[i]]--;
            }else{
                if(mp.find(tolower(word[i]))!=mp.end() && mp[tolower(word[i])]==0){
                    ans++;
                    cout<<word[i]<<" ";
                    mp.erase(tolower(word[i]));
                    mp.erase(word[i]);
                }else{
                    mp.erase(tolower(word[i]));
                    mp.erase(word[i]);
                }
            }
        }
        return ans;
    }
};