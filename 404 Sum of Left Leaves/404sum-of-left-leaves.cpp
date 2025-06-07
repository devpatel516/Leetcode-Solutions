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
    int helper(TreeNode *root,int sum){
        if(root==NULL){
            return 0;
        }

        if(root->left && root->left->left==NULL && root->left->right==NULL){
            sum+=root->left->val;
        }
        sum+=helper(root->left,0);
        sum+=helper(root->right,0);
        return sum;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return helper(root,0);
    }
};