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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*> mp;
        unordered_set<int> childrens;

        for(auto k:descriptions){
            int parent=k[0];
            int child=k[1];
            int isleft=k[2];

            if(mp.find(parent)==mp.end()){
                mp[parent]=new TreeNode(parent);
            }

            if(mp.find(child)==mp.end()){
                mp[child]=new TreeNode(child);
            }

            if(isleft){
                mp[parent]->left=mp[child];
            }
            else{
                mp[parent]->right=mp[child];
            }

            childrens.insert(child);
        }

        for(auto k:descriptions){
            if(childrens.find(k[0])==childrens.end()){
                return mp[k[0]];
            }
        }
        return NULL;
    }
};