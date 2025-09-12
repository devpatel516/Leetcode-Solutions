class Solution {
public:
    vector<int> diStringMatch(string s) {
        int max=s.size();
        int min=0;
        vector<int> ans;
        for(int i=0;i<s.size();i++){
            if(s[i]=='I'){
                ans.push_back(min);
                min++;
            }
            else{
                ans.push_back(max);
                max--;
            }
        }
        if(min<max){
            ans.push_back(max);
        }
        else{
            ans.push_back(min);
        }
        return ans;
    }
};