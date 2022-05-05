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
    int pathSum(TreeNode* root, int targetSum) {
        if(root){
            sol(root,targetSum);
            pathSum(root->left,targetSum);
            pathSum(root->right,targetSum);            
        }
        return ans;
    }
    void sol(TreeNode* root,long sum){
        if(!root)return;
        if(sum==root->val)ans++;
        sol(root->left,sum-root->val);
        sol(root->right,sum-root->val);
    }
};