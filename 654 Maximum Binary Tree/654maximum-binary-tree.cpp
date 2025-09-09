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
    TreeNode *helper(vector<int> &nums,int s,int e){
        if(s>e){
            return NULL;
        }
        int maxind=s;
        for(int i=s;i<=e;i++){
            if(nums[i]>nums[maxind]){
                maxind=i;
            }
        }
        TreeNode *root=new TreeNode(nums[maxind]);
        root->left=helper(nums,s,maxind-1);
        root->right=helper(nums,maxind+1,e);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode *root;
        root=helper(nums,0,nums.size()-1);
        return root;
    }
};