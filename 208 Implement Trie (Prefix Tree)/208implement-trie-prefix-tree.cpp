class Trie {
public:
    Trie *child[26];
    bool isEnd;
    Trie() {
        for(int i=0;i<26;i++){
            child[i]=NULL;
        }
        isEnd=false;
    }
    
    void insert(string word) {
        Trie *node=this;

        for(auto ch:word){
            int index=ch-'a';
            if(node->child[index]==NULL){
                node->child[index]=new Trie();
            }
            node=node->child[index];
        }
        node->isEnd=true;
    }
    
    bool search(string word) {
        Trie *node=this;
        for(auto ch:word){
            int index=ch-'a';
            if(node->child[index]==NULL){
                return false;
            }
            node=node->child[index];
        }
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        Trie *node=this;
        for(auto ch:prefix){
            int index=ch-'a';
            if(node->child[index]==NULL){
                return false;
            }
            node=node->child[index];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */