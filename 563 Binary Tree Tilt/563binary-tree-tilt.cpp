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
    int ans=0;
    int help(TreeNode *root){

        if(root==NULL){
            return 0;
        }
        int ls=help(root->left);
        int rs=help(root->right);
        ans+=abs(ls-rs);
        return ls+rs+root->val;
    }
    int findTilt(TreeNode* root) {
        help(root);
        return ans;
    }
};