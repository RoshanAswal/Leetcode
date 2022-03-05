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
    int ans=0;
    void dfs(TreeNode* root,int mul,int temp,map<TreeNode*,int> &m){
        if(!root)return;
        if(!(root->left) && !(root->right)){
            temp=(mul*temp)+root->val;
            ans+=temp;
            return;
        }
        m[root]=1;
        temp=(mul*temp)+root->val;
        if(!m[root->left])dfs(root->left,10,temp,m);
        if(!m[root->right])dfs(root->right,10,temp,m);
    }
    int sumNumbers(TreeNode* root) {
        if(!root)return 0;
        if(!root->left && !root->right)return root->val;
        map<TreeNode*,int> m;
        dfs(root,1,0,m);
        return ans;
    }
};