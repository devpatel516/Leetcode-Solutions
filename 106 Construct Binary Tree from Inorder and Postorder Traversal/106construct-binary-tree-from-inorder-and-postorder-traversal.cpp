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
    TreeNode *helper(vector<int>& preorder,int preStart,int preEnd,vector<int>& inorder,int inStart,int inEnd,unordered_map<int,int> &inMap){
        if(preStart>preEnd || inStart>inEnd){
            return NULL;
        }
        TreeNode *root = new TreeNode(preorder[preEnd]);
        int inRoot=inMap[root->val];
        int numsLeft=inRoot-inStart;
        root->left=helper(preorder,preStart,preStart+numsLeft-1,inorder,inStart,inRoot-1,inMap);
        root->right=helper(preorder,preStart+numsLeft,preEnd-1,inorder,inRoot+1,inEnd,inMap);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> inMap;
        for(int i=0;i<inorder.size();i++){
            inMap[inorder[i]]=i;
        }
        return helper(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,inMap);
    }
};