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
    bool sol(TreeNode* root){
        if(!root)return false;
        if(!(root->left) && !(root->right)){
            if(root->val==0)return false;
            else return true;
        }
        bool ans1=sol(root->left);
        if(!ans1)root->left=NULL;
        bool ans2=sol(root->right);
        if(!ans2)root->right=NULL;
        if(ans1 || ans2 || root->val==1)return true;
        return false;
    }
    TreeNode* pruneTree(TreeNode* root) {
        if(!root)return root;
        TreeNode *temp=root;
        bool ans=sol(root);
        if(ans || temp->val==1)return temp;
        else return NULL;
    }
};
























