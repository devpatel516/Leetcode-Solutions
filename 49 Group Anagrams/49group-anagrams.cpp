class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //more optimized;
        unordered_map<string,vector<string>> mp;
        for(auto s:strs){
            vector<int> count(26,0);
            for(auto c:s){
                count[c-'a']++;
            }

            string key="";
            for(auto c:count){
                key+="#"+to_string(c);
            }
            mp[key].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto p:mp){
            ans.push_back(p.second);
        }
        return ans;
    }
};