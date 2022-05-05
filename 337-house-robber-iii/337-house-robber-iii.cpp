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
    map<TreeNode*,int> m;
    int rob(TreeNode* root) {
        if(!root)return 0;
        if(m.count(root))return m[root];
        int total=0;
        if(root->right)
            total+=rob(root->right->right)+rob(root->right->left);
        if(root->left)
            total+=rob(root->left->right)+rob(root->left->left);
        int l=rob(root->left);
        int r=rob(root->right);
        return m[root]=max(root->val+total,l+r);
    }
};