class Solution {
public:
    string pushDominoes(string dominoes) {
        int n=dominoes.size();
        vector<int> f(n,0);
        int force=0;
        for(int i=0;i<n;i++){
            if(dominoes[i]=='R'){
                force=n;
            }
            else if(dominoes[i]=='L'){
                force=0;
            }
            else{
                force=max(force-1,0);
            }
            f[i]+=force;
        }
        force=0;
        for(int i=n-1;i>=0;i--){
            if(dominoes[i]=='L'){
                force=n;
            }
            else if(dominoes[i]=='R'){
                force=0;
            }
            else{
                force=max(force-1,0);
            }
            f[i]-=force;
        }
        string ans;
        for(auto c:f){
            if(c>0){
                ans+='R';
            }
            else if(c<0){
                ans+='L';
            }
            else{
                ans+='.';
            }
        }
        return ans;
    }
};
