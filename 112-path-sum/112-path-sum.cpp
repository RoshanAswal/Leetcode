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
    bool ans=false;
    void sol(TreeNode* root,int sum,int tar){
        if(root){
            if((!root->left && !root->right) || ans){
                if(sum+root->val==tar)ans=true;
                return;
            }
            sol(root->left,sum+root->val,tar);
            sol(root->right,sum+root->val,tar);
        }
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)return 0;
        sol(root,0,targetSum);
        return ans;
    }
};