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
    void sol(TreeNode* root,int &sum){
        if(!root)return;
        if(root->right)sol(root->right,sum);
        root->val=root->val+sum;
        sum=root->val;
        if(root->left)sol(root->left,sum);
    }
    TreeNode* convertBST(TreeNode* root) {
        int sum=0;
        sol(root,sum);
        return root;
    }
};