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
    void solve(TreeNode* node,bool left,int l,int &ans){
        if(!node){
            return ;
        }
        ans=max(ans,l);
        if(left){
            solve(node->left,false,l+1,ans);
            solve(node->right,true,1,ans);
        }
        else{
            solve(node->right,true,l+1,ans);
            solve(node->left,false,1,ans);
        }
    }
    int longestZigZag(TreeNode* root) {
        int ans=0;
        solve(root,true,0,ans);
        solve(root,false,0,ans);
        return ans;
    }
};