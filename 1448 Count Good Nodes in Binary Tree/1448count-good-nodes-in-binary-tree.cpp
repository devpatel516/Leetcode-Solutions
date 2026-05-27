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
    int helper(TreeNode* root,int maxVal){
        if(!root){
            return 0;
        }
        int c=0;
        if(root->val>=maxVal){
            c=1;
            maxVal=root->val;
        }
        int left=helper(root->left,maxVal);
        int right=helper(root->right,maxVal);
        return c+left+right;
    }
    int goodNodes(TreeNode* root) {
        return helper(root,root->val);
    }
};