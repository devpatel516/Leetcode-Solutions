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
    void helper(TreeNode* root,set<int> &ans){
        if(!root){
            return ;
        }
        ans.insert(root->val);
        helper(root->left,ans);
        helper(root->right,ans);
    }
    int findSecondMinimumValue(TreeNode* root) {
        set<int> ans;
        vector<int> a;
        helper(root,ans);
        for(auto c:ans){
            a.push_back(c);
        }
        sort(a.begin(),a.end());
        if(a.size()<=1){
            return -1;
        }
        return a[1];
    }
};