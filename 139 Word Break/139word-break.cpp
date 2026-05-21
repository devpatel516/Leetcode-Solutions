class Trie{
public:
    Trie* child[26];
    bool isEnd;
    Trie(){
        for(int i=0;i<26;i++){
            child[i]=NULL;
        }
        isEnd=false;
    }

    void insert(string word){
        Trie* node=this;
        for(char ch:word){
            int index=ch-'a';
            if(node->child[index]==NULL){
                node->child[index]=new Trie();
            }
            node=node->child[index];
        }
        node->isEnd=true;
    }
};
class Solution {
public:
    bool solve(int idx,string &s,Trie *root,vector<int> &dp){
        if(idx==s.size()){
            return true;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        Trie* node=root;
        for(int i=idx;i<s.size();i++){
            int index=s[i]-'a';

            if(node->child[index]==NULL){
                break;
            }
            node=node->child[index];
            if(node->isEnd){
                if(solve(i+1,s,root,dp)){
                    return dp[idx]=true;
                }
            }
        }
        return dp[idx]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        Trie t;
        for(auto word:wordDict){
            t.insert(word);
        }
        vector<int> dp(s.size(),-1);
        return solve(0,s,&t,dp);
    }
};