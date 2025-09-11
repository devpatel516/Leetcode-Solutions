class Solution {
public:
    bool isVowel(char c){
        c=tolower(c);
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
            return true;
        }
        return false;
    }
    string sortVowels(string s) {
        vector<char> a;
        for(int i=0;i<s.size();i++){
            if(isVowel(s[i])){
                a.push_back(s[i]);
            }
        }
        sort(a.begin(),a.end());
        int j=0;
        for(int i=0;i<s.size();i++){
            if(isVowel(s[i])){
                s[i]=a[j];
                j++;
            }
        }
        return s;
    }
};