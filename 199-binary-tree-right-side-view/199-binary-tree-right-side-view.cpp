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
    vector<int> ans;
    int d=-1;
    void sol(TreeNode* root,int c){
        if(root==NULL){
            d=max(d,c-1);
            return;
        }
        if(c>d)
            ans.push_back(root->val);
        sol(root->right,c+1);
        sol(root->left,c+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL)return ans;
        sol(root,0);
        return ans;
    }
};