class Solution {
public:
    void helper(TreeNode* root, int k, int &c, int &ans) {
        if (root == NULL) return;

        helper(root->left, k, c, ans);
        if (ans != -1) return;
        c++;
        if (c == k) {
            ans = root->val;
            return;
        }
        helper(root->right, k, c, ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        int c = 0;
        int ans = -1;  
        helper(root, k, c, ans);
        return ans;
    }
};
