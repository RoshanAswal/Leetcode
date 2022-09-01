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
    int sol(TreeNode *root,int &ans){
        if(!root)return 0;
        int a=0,b=0;
        a+=sol(root->left,ans);
        b+=sol(root->right,ans);
        if(root->left && root->left->val==root->val)a++;
        else a=0;
        if(root->right && root->right->val==root->val)b++;
        else b=0;
        ans=max(ans,a+b);
        return max(a,b);
    }
    int longestUnivaluePath(TreeNode* root) {
        int ans=0;
        int temp=sol(root,ans);
        return max(ans,temp);
    }
};