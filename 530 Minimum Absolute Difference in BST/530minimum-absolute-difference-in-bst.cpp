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
    int getMinimumDifference(TreeNode* root) {
        int result = INT_MAX;
        int prevres = INT_MIN;
        inorder(result, prevres, root);
        return result;
    }

private:
    void inorder(int& result, int& prevres, TreeNode* root) {
        if (root==nullptr) {return;
        }
        inorder(result, prevres, root->left);
        if (prevres != INT_MIN) {
            result = min(result, root->val - prevres);
        }
        prevres = root->val;
        inorder(result, prevres, root->right);
    }
};