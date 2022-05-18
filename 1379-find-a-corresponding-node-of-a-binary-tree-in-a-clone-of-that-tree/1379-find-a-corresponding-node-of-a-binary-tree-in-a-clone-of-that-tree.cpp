/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    // TreeNode* ans=NULL;
    void sol(TreeNode* clon,int val,TreeNode* &ans){
        if(!clon || ans!=NULL)return;
        if(clon->val==val){
            ans=clon;return;
        }
        sol(clon->left,val,ans);
        sol(clon->right,val,ans);
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* ans=NULL;
        sol(cloned,target->val,ans);
        return ans;
    }
};