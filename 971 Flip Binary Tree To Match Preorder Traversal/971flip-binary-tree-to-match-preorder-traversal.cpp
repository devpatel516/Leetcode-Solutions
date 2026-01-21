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
    vector<int> res;
    int i=0;
    bool possible=true;
    void preorder(TreeNode* root,vector<int> &voyage){
        if(!root || !possible){
            return ;
        }
        if(root->val!=voyage[i]){
            possible=false;
            return ;
        }
        i++;
        if(root->left && i<voyage.size() && root->left->val!=voyage[i]){
            res.push_back(root->val);
            swap(root->left,root->right);
        }
        preorder(root->left,voyage);
        preorder(root->right,voyage);
    }
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        preorder(root,voyage);
        if(!possible){
            return {-1};
        }
        return res;
    }
};