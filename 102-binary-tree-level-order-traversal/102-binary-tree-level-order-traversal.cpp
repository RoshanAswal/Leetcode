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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> ans;
        while(!q.empty()){
            int s=q.size();
            vector<int> temp;
            for(int i=0;i<s;i++){
                TreeNode* fr=q.front();
                q.pop();
                if(fr->left)q.push(fr->left);
                if(fr->right)q.push(fr->right);                
                temp.push_back(fr->val);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};