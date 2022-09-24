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
    vector<vector<int>> ans;
    void sol(TreeNode* root,int tar,int temp,vector<int> v){
        if(root && !root->left && !root->right){
            if(temp+root->val==tar){
                v.push_back(root->val);
                ans.push_back(v);
            }
            return;
        }else if(!root)return;
        v.push_back(root->val);
        sol(root->left,tar,temp+root->val,v);
        sol(root->right,tar,temp+root->val,v);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> v;
        sol(root,targetSum,0,v);
        return ans;
    }
};