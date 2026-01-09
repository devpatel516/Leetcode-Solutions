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
    int maxDepth(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        return 1+max(maxDepth(root->left),maxDepth(root->right));
    }
    TreeNode* subtreeWithAllDeepestHelper(TreeNode* root,int depth,int &md){
        if(root==NULL){
            return NULL;
        }
        TreeNode *left=subtreeWithAllDeepestHelper(root->left,depth+1,md);
        TreeNode *right=subtreeWithAllDeepestHelper(root->right,depth+1,md);
        
        if(depth==md){
            return root;
        }
        if(!left){
            return right;
        }
        if(!right){
            return left;
        }
        return root;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int md=maxDepth(root);
        return subtreeWithAllDeepestHelper(root,1,md);
    }
};