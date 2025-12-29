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
    int minDepth(TreeNode* root) {
        if(!root){
            return 0;
        }
        queue<TreeNode *> q;
        q.push(root);
        int ans=INT_MAX;
        int temp=0;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                auto p=q.front();
                q.pop();
                if(!p->left && !p->right){
                    ans=min(ans,temp);
                }
                if(p->left){
                    q.push(p->left);
                }
                if(p->right){
                    q.push(p->right);
                }
            }
            temp++;
        }
        return ans+1;
    }
};