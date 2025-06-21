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
    void helper(TreeNode* root,int &sum,int val){
        if(root==NULL){
            return;
        }
        val=val<<1 | root->val;
        if(!root->left && !root->right){
            sum+=val;
            return ;
        }
        helper(root->left,sum,val);
        helper(root->right,sum,val);
    }
    int sumRootToLeaf(TreeNode* root) {
        int sum=0;
        helper(root,sum,0);
        return sum;
    }
};