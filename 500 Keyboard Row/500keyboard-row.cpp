class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_map<char,int> mp;
        string r1="qwertyuiop";
        string r2="asdfghjkl";
        string r3="zxcvbnm";

        for(auto c:r1){
            mp[c]=1;
        }

        for(auto c:r2){
            mp[c]=2;
        }

        for(auto c:r3){
            mp[c]=3;
        }


        vector<string> ans;

        for(int i=0;i<words.size();i++){
            string temp=words[i];
            bool v=true;
            for(int j=1;j<temp.size();j++){
                if(mp[tolower(temp[j])]!=mp[tolower(temp[j-1])]){
                    v=false;
                    break;
                }
            }
            if(v){
                ans.push_back(temp);
            }
        }
        return ans;
    }
};