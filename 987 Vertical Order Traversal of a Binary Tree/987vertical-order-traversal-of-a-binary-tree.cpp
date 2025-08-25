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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,vector<int>>> nodes;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            int x=p.second.first;
            int y=p.second.second;
            nodes[x][y].push_back(p.first->val);
            if(p.first->left){
                q.push({p.first->left,{x-1,y+1}});
            }
            if(p.first->right){
                q.push({p.first->right,{x+1,y+1}});
            }
        }
        vector<vector<int>> ans;
        for(auto p:nodes){
            vector<int> col;
            for(auto q:p.second){
                auto vec=q.second;
                sort(vec.begin(),vec.end());
                col.insert(col.end(),vec.begin(),vec.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};