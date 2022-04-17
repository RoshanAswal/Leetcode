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
    TreeNode* ans=NULL,*temp=NULL;
    void sol(TreeNode* root){
        if(root){
            sol(root->left);
            if(temp==NULL)
                temp=root;     
            else
                ans->right=root;
            ans=root;
            ans->left=NULL;
            sol(root->right);            
        }
    }
    TreeNode* increasingBST(TreeNode* root) {
        sol(root);
        return temp;
    }
};