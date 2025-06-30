class Solution {
public:
    vector<string> mp={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void backtrack(string &digits,int index,string path,vector<string> &result){
        if(index==digits.size()){
            result.push_back(path);
            return;
        }
        string letters=mp[digits[index]-'0'];
        for(auto k:letters){
            path.push_back(k);
            backtrack(digits,index+1,path,result);
            path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if(digits.empty()){
            return result;
        }
        string path="";
        backtrack(digits,0,path,result);
        return result;
    }
};