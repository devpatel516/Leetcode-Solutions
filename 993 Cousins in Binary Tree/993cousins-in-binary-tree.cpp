/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode *,TreeNode *> parent;
    void dfs(TreeNode *child,TreeNode *par){
        if(!child){
            return ;
        }
        parent[child]=par;
        dfs(child->left,child);
        dfs(child->right,child);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root,NULL);
        TreeNode *px=NULL;
        TreeNode *py=NULL;
        int dx=-1,dy=-1;
        queue<pair<TreeNode *,int>> q;
        q.push({root,0});
        while(!q.empty()){
            auto [node,depth]=q.front();
            q.pop();
            if(node->val==x){
                px=parent[node];
                dx=depth;
            }
            if(node->val==y){
                py=parent[node];
                dy=depth;
            }
            
            if(node->left){
                q.push({node->left,depth+1});
            }
            if(node->right){    
                q.push({node->right,depth+1});
            }
        }
        return dx==dy && px!=py;
    }
};