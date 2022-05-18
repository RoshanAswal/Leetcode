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
    TreeNode* ans=NULL;
    void sol(TreeNode* clon,int val){
        if(!clon || ans!=NULL)return;
        if(clon->val==val){
            ans=clon;return;
        }
        sol(clon->left,val);
        sol(clon->right,val);
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        sol(cloned,target->val);
        return ans;
    }
};