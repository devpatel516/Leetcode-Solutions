class Solution {
public:
    class TrieNode{
    public:
        vector<TrieNode*> children;
        int childcount;
        char data;
        bool isleaf;
        
        TrieNode(char data){
            childcount = 0;
            this->data = data;
            children = vector<TrieNode*>(26, nullptr);
            isleaf = false;
        }
    };

    void insert(TrieNode *root, string &s){
        TrieNode *curr = root;
        for(auto c : s){
            int i = c - 'a';
            if(curr->children[i] == nullptr){
                curr->children[i] = new TrieNode(c);
                curr->childcount++;
            }
            curr = curr->children[i];
        }
        curr->isleaf = true;
    }
    
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        TrieNode *root = new TrieNode('\0');
        for(auto &s : strs){ 
            insert(root, s);
        }
        TrieNode *curr = root;
        while(curr->childcount == 1 && !curr->isleaf){
            for(int i = 0; i < 26; i++){
                if(curr->children[i] != nullptr){
                    curr = curr->children[i];
                    ans += curr->data; 
                    break;
                }
            }
        }
        
        return ans;
    }
};
