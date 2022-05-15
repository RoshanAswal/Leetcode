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
    int ans=0,d=0;
    void dfs(TreeNode* root,int t){
        if(!root)return;
        if(!root->left && !root->right){
            if(t>d){
                ans=0;d=t;
            }
            if(d==t)ans+=root->val;return;
        }
        t++;
        dfs(root->left,t);
        dfs(root->right,t);
    }
    int deepestLeavesSum(TreeNode* root) {
        int t=0;
        dfs(root,t);
        return ans;
    }
};