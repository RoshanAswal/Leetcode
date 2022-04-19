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
    TreeNode* temp=NULL,*temp2=NULL,*prev=NULL;
    void sol(TreeNode* root){
        if(!root)return;
        sol(root->left);
        if(!temp && prev && prev->val>root->val)
            temp=prev;            
        if(temp && prev->val>root->val)
            temp2=root;
        prev=root;
        sol(root->right);
    }
    void recoverTree(TreeNode* root) {
        sol(root);
        swap(temp->val,temp2->val);
        return;
    }
};
