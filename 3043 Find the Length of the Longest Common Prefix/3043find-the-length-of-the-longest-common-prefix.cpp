class Trie{
    public:
        Trie* child[10];

        Trie(){
            for(int i=0;i<10;i++){
                child[i]=NULL;
            }
        }

        void insert(string word){
            Trie* node=this;
            for(char ch:word){
                int index=ch-'0';
                if(node->child[index]==NULL){
                    node->child[index]=new Trie();
                }
                node=node->child[index];
            }
        }

        int findPrefix(string word){
            Trie *node=this;
            int c=0;
            for(auto ch:word){
                int index=ch-'0';
                if(node->child[index]==NULL){
                    break;
                }
                c++;
                node=node->child[index];
            }
            return c;
        }
};
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie t;
        for(int i=0;i<arr1.size();i++){
            t.insert(to_string(arr1[i]));
        }
        int ans=0;
        for(int i=0;i<arr2.size();i++){
            ans=max(ans,t.findPrefix(to_string(arr2[i])));
        }
        return ans;
    }
};