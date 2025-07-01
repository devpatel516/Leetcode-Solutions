class Solution {
public:
    int possibleStringCount(string word) {
       vector<pair<char,int>> v;
       int n=word.size();
       int i=0;
       while(i<n){
            char current=word[i];
            int c=0;
            while(i<n && current==word[i]){
                c++;
                i++;
            }
            v.push_back({current,c});
       }
       int ans=0; 
       for(auto k:v){
            ans+=k.second-1;
       }
       return ans+1;
    }
};