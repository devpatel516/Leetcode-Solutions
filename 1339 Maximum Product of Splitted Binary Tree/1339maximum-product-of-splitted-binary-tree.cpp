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
    long long ans=0,totalsum=0;
    long long subarraysum(TreeNode *root){
        if(root==NULL){
            return 0;
        }
        int lefts=subarraysum(root->left);
        int rights=subarraysum(root->right);
        root->val=root->val+lefts+rights;
        return root->val;
    }
    void func(TreeNode *root,int totalsum){
        if(root==NULL){
            return ;
        }
        long long ls=root->val;
        ans=max((totalsum-ls)*ls,ans);
        func(root->left,totalsum);
        func(root->right,totalsum);
    }
    int maxProduct(TreeNode* root) {
        totalsum=subarraysum(root);
        func(root,totalsum);
        return ans%(int)(1e9+7);
    }
};