class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
        unordered_map<string,int> m;
        for (auto t:words){
            string temp="";
            for(auto k:t){
                temp+=morse[k-'a'];
            }
            m[temp]++;
        }
        return m.size();
    }
};