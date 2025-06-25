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
    int time(unordered_map<TreeNode*,TreeNode*> &map,TreeNode *target){
        unordered_map<TreeNode*,bool> vis;
        queue<TreeNode*> q;
        q.push(target);
        vis[target]=true;
        int dis=0;
        while(!q.empty()){
            int size=q.size();
            int v=0;
            for(int i=0;i<size;i++){
                auto node=q.front();
                q.pop();
                if(node->left && !vis[node->left]){
                    v=1;
                    q.push(node->left);
                    vis[node->left]=true;
                }
                if(node->right && !vis[node->right]){
                    v=1;
                    q.push(node->right);
                    vis[node->right]=true;
                }
                if(map[node] && !vis[map[node]]){
                    v=1;
                    q.push(map[node]);
                    vis[map[node]]=true;
                }
            }
            if(v) dis++;
        }
        return dis;
    }
    TreeNode* MapAndFind(TreeNode *root,unordered_map<TreeNode*,TreeNode*> &map,int start){
        queue<TreeNode*> q;
        q.push(root);
        TreeNode *res;
        while(!q.empty()){
            TreeNode *node=q.front();
            q.pop();
            if(node->val==start){
                res=node;
            }
            if(node->left){
                map[node->left]=node;
                q.push(node->left);
            }
            if(node->right){
                map[node->right]=node;
                q.push(node->right);
            }
        }
        return res;
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*> map;
        TreeNode *target=MapAndFind(root,map,start);
        return time(map,target);
    }
};