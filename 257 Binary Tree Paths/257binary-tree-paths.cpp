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
    void helper(TreeNode* root,vector<string> &a,string s){
        if(root==NULL){
            return;
        }
        if(!s.empty()){
            s+="->";
        }
        s+=to_string(root->val);
        if(root->left==NULL && root->right==NULL){
            a.push_back(s);
            return;
        }
        helper(root->left,a,s);
        helper(root->right,a,s);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string s;
        vector<string> a;
        helper(root,a,s);
        return a;
    }
};