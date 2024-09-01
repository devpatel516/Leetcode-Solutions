class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int c,max=0;
        for(auto s:sentences){
            c=0;
            for(auto x:s){
                if(x==' '){
                    c++;
                }
            }
            if(max<c){
                max=c;
            }
        }
        return max+1;
    }
};