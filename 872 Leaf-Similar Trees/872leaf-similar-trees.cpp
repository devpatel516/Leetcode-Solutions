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
    void dfs(TreeNode *root,vector<int> &a){
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            a.push_back(root->val);
            return;
        }
        dfs(root->left,a);
        dfs(root->right,a);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> l1,l2;
        dfs(root1,l1);
        dfs(root2,l2);
        int i=0;
        if(l1.size()!=l2.size())return false;
        for(auto c:l1){
            if(c!=l2[i]){
                return false;
            }
            i++;
        }
        return true;
    }
};