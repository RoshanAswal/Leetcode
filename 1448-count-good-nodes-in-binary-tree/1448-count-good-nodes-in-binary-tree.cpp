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
    void sol(TreeNode *root,int &ans,int mx){
        if(!root)return;
        mx=max(mx,root->val);
        if(root->val>=mx)ans++;
        sol(root->left,ans,mx);
        sol(root->right,ans,mx);
    }
    int goodNodes(TreeNode* root) {
        int ans=0;
        sol(root,ans,root->val);
        return ans;
    }
};