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
    int currVal=INT_MIN;
    int currCount=0;
    int maxCount=0;
    vector<int> result;
    void inorder(TreeNode* root){
        if(!root){
            return ;
        }
        inorder(root->left);
        if(currVal!=root->val){
            currVal=root->val;
            currCount=1;
        }
        else{
            currCount++;
        }
        if(currCount>maxCount){
            maxCount=currCount;
            result.clear();
            result.push_back(currVal);
        }else if(currCount==maxCount){
            result.push_back(currVal);
        }
        inorder(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return result;
    }
};