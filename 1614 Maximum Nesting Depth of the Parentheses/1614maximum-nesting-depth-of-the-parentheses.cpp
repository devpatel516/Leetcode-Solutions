class Solution {
public:
    int maxDepth(string s) {
        int k=0;
        int ans=0;
        for(auto c:s){
            if(c=='('){
                k++;
                ans=max(ans,k);
            }
            else if(c==')'){
                k--;
            }
        }
        return ans;
    }
};