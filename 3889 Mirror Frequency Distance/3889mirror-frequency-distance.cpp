class Solution {
public:
    int mirrorFrequency(string s) {
        unordered_map<char,int> mp;
        for(auto c:s){
            mp[c]++;
        }
         unordered_map<char, char> mirror = {{'a','z'}, {'b','y'}, {'c','x'}, {'d','w'}, {'e','v'},{'f','u'},{'g','t'}, {'h','s'}, {'i','r'}, {'j','q'}, {'k','p'}, {'l','o'}, {'m','n'}, {'n','m'}, {'o','l'}, {'p','k'}, {'q','j'}, {'r','i'},{'s','h'}, {'t','g'}, {'u','f'}, {'v','e'}, {'w','d'}, {'x','c'},{'y','b'}, {'z','a'},{'0','9'}, {'1','8'}, {'2','7'}, {'3','6'}, {'4','5'},{'5','4'}, {'6','3'}, {'7','2'}, {'8','1'}, {'9','0'}};
        int c=0;
        unordered_set<char> visited;
        for(auto [ch,count]:mp){
            if(visited.count(ch)) continue;
            int mc=mp.count(mirror[ch])?mp[mirror[ch]]:0;
            c+=abs(count-mc);
            visited.insert(ch);
            visited.insert(mirror[ch]);
        }
        return c;
    }
};