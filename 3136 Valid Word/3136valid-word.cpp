class Solution {
public:
    bool isValid(string word) {
        if (word.size() < 3) {
            return false;
        }
        bool con = false;
        bool vow = false;
        set<char> s = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        for(auto ch:word){
            if(!isdigit(ch) && !isalpha(ch)){
                return false;
            }
            if(isalpha(ch)){
                if(s.count(ch)){
                    vow=true;
                }
                else{
                    con=true;
                }
            }
        }
        return vow && con;
    }
};