class Solution
{
private:
    vector<TreeNode *> inorder;
    void inOrder(TreeNode *ptr)
    {
        if (ptr == nullptr)
            return;
        inOrder(ptr->left);
        inorder.push_back(ptr);
        inOrder(ptr->right);
    }

    TreeNode *balancedbst(int left, int right)
    {
        if (left > right)
            return nullptr;
        int mid = (left + right) / 2;
        TreeNode *curr = inorder[mid];
        curr->left = balancedbst(left, mid - 1);
        curr->right = balancedbst(mid + 1, right);
        return curr;
    }

public:
    TreeNode *balanceBST(TreeNode *root)
    {
        inOrder(root);
        return balancedbst(0, inorder.size() - 1);
    }
};