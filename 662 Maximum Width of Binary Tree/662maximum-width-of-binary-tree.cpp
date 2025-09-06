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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});
        long long ans=0;
        while(!q.empty()){
            long long size=q.size();
            long long first=0,second=0;
            long long minInd=q.front().second; 
            for(long long i=0;i<size;i++){
                long long ind=q.front().second-minInd;
                if(i==0){
                    first=ind;
                }
                else if(i==size-1){
                    second=ind;
                }
                ans=max(ans,second-first+1);
                if(q.front().first->left){
                    q.push({q.front().first->left,2*ind+1});
                }
                if(q.front().first->right){
                    q.push({q.front().first->right,2*ind+2});
                }
                q.pop();
            }
        }
        return ans;
    }
};