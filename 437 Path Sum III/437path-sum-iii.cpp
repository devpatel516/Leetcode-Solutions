class Solution {
public:
    void helper(TreeNode* root, long long targetSum, int &count){
        if(!root){
            return;
        }

        if(root->val == targetSum){
            count++;
        }

        helper(root->left, targetSum - root->val, count);
        helper(root->right, targetSum - root->val, count);
    }

    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;

        int count = 0;

        helper(root, targetSum, count);
        count += pathSum(root->left, targetSum);
        count += pathSum(root->right, targetSum);

        return count;
    }
};
