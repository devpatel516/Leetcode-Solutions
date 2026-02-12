class Solution {
public:
    int longestBalanced(string s) {
        int ans=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            vector<int> ch(26,0); 
            for(int j=i;j<n;j++){
                ch[s[j]-'a']++;
                int temp=0;
                bool v=true;
                for(int k=0;k<26;k++){
                    if(ch[k]>0){
                        if(temp==0){
                            temp=ch[k];
                        }
                        else if(temp!=ch[k]){
                            v=false;
                            break;
                        }
                    }
                }
                if(v){
                    ans=max(ans,j-i+1);
                }
            }
        }
        return ans;
    }
};